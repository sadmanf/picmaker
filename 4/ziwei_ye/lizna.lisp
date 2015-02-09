(in-package #:lizna)

(defvar *default-path* #p"~/images/")
(defvar *current-image-stack* nil)

(defclass image ()
  ((name :initform (error "Must supply a name.") :initarg :name :accessor name)
   (x :initform (error "Must supply x-value.") :initarg :x :accessor bpm-x)
   (y :initform (error "Must supply y-value.") :initarg :y :accessor bpm-y)
   (path :initform *default-path* :initarg :path ::accessor path)
   (maxval :initform 255 :initarg :maxval :reader maxval)
   (img-array :initform nil :accessor img-array)))

(defgeneric print-pbm-data (image stream &key &allow-other-keys))

(defmacro def-pbm-format (format-name &key slots ext matrix-type init format-str format-elem)
  (let ((img-sym (intern (concatenate 'string format-name "-IMAGE"))))
    `(progn
	 (defclass ,img-sym (image) ,slots)

	 (defmethod initialize-instance :after ((image ,img-sym) &key)
		    (push image *current-image-stack*)
		    (with-slots (img-array x y path name) image
		      (setf img-array (make-array `(,x ,y) :element-type ,matrix-type :initial-element ,init))
		      (setf path (merge-pathnames path (concatenate 'string name ,ext)))))

	 (defmethod print-pbm-data ((image ,img-sym) stream &key &allow-other-keys)
	   (with-slots (img-array x y maxval) image
	     (format stream ,(concatenate 'string format-name "~%~d ~d~%~d~%") x y maxval)
	     (loop for y-val upto (- y 1) do
		  (loop for x-val upto (- x 1) do
		       (let ((elem (aref img-array y-val x-val)))
			 (format stream ,format-str ,@format-elem #\tab)))
		  (format stream "~%")))))))	    

;; (def-pbm-format "P1" 
;;     :ext ".pam"
;;     :matrix-type 'simple-vector
;;     :init #(0 0 0)
;;     :format-str "~d ~d ~d~a"
;;     :format-elem ((aref elem 0) (aref elem 1) (aref elem 2))    
;;     :slots nil)

;; (def-pbm-format "P2" 
;;     :ext ".pbm"
;;     :matrix-type 'simple-vector
;;     :init #(0 0 0)
;;     :format-str "~d ~d ~d~a"
;;     :format-elem ((aref elem 0) (aref elem 1) (aref elem 2))    
;;     :slots nil)

(def-pbm-format "P3" 
    :ext ".ppm"
    :matrix-type 'simple-vector
    :init #(0 0 0)
    :format-str "~d ~d ~d~a"
    :format-elem ((aref elem 0) (aref elem 1) (aref elem 2))    
    :slots nil)

(defun new-image (type x y name)
  (make-instance (intern (concatenate 'string type "-IMAGE"))
		 :x x :y y :name name))

(defmethod print-object ((image image) stream)
  (print-unreadable-object (image stream :type t :identity nil)
    (princ (name image) stream)))

(defmethod save-image ((image image))
  (ensure-directories-exist (path image))
  (with-open-file (stream (path image)
			  :direction :output
			  :if-exists :supersede
			  :if-does-not-exist :create
			  :element-type :default)
    (print-pbm-data image stream))
  (format t "Saved image to ~a." (path image)))

;; (defclass pbm-reader ()
;;   ((magic-number-p :initform nil :accessor mn)
;;    (x-p :initform nil :accessor x-p)
;;    (y-p :initform nil :accessor y-p)
;;    (maxval-p :initform nil :accessor val-p)))

;; (defun load-pbm (path)
;;   (flet ((whitespace-p (c) (member c '(#\Space #\Tab #\Newline) :test 'eql))
;; 	 (comment-p (str) (eql (subseq str 0 1) #\#)))
;;     (with-open-file (stream path :direction :input)
;;       (loop with buffer = (split-sequence-if #'whitespace-p (read-sequence 
;; 							     (make-string (file-length stream))
;; 							     stream) :remove-empty-subseqs)
;; 	   with reader = (make-instance 'bpm-reader)
;; 	   for 
