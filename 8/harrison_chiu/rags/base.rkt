#lang racket

(provide
 make-image
 image-rows
 image-cols
 image-max
 image-pixels
 image-pixel
 set-image-pixel!
 fill-image!
 image->string
 write-image!

 make-pixel
 pixel-red
 pixel-green
 pixel-blue
 set-pixel-red!
 set-pixel-green!
 set-pixel-blue!
 set-pixel-all!
 pixel->string
 )

; red, green, blue, and max are integers
(struct pixel ((red #:mutable)
	       (green #:mutable)
	       (blue #:mutable)
	       max))

; pixels is a vector, max is an integer
(struct image (pixels rows cols max))

(define make-image
  (lambda (rows cols (max 255))
    (let ((img (image (make-vector (* rows cols))
		      rows cols max)))
      (fill-image! img (make-pixel 0 0 0))
      img)))

(define image-pixel
  (lambda (img row col)
    (vector-ref 
     (image-pixels img)
     (2d->1d row col (image-rows img)))))

(define set-image-pixel!
  (lambda ; case-lambda 
      (img row col
	   #:red (red (pixel-red (image-pixel img row col)))
	   #:green (green (pixel-green (image-pixel img row col)))
	   #:blue (blue (pixel-blue (image-pixel img row col))))
    (set-pixel-all! #:red red #:green green #:blue blue)))
    ;; ((img row col 
    ;; 	  pix)
    ;;  (vector-set! 
    ;;   (image-pixels img)
    ;;   (2d->1d row col (image-rows img))
    ;;   pix))))


(define 2d->1d
  (lambda (row col rows)
    (+ (* rows
	  row)
       col)))

(define fill-image!
  (lambda (img pix)
    (vector-fill! (image-pixels img) pix)))

(define image->string
  (lambda (img)
    (string-append* "P3 "
		    (number->string (image-rows img))
		    " "
		    (number->string (image-cols img))
		    " "
		    (number->string (image-max img))
		    " "
		    (map pixel->string (vector->list (image-pixels img))))))

(define write-image!
  (lambda (img filename)
    (define out (open-output-file filename
				  #:mode 'text
				  #:exists 'replace))
    (display (image->string img) out)
    (close-output-port out)))



(define make-pixel
  (lambda (red green blue (max 255))
    (pixel red green blue max)))

;default setters and getters

(define set-pixel-all!
  (lambda (pix #:red (red (pixel-red pix))
	       #:green (green (pixel-green pix))
	       #:blue (blue (pixel-blue pix)))
    (set-pixel-red! pix red)
    (set-pixel-green! pix green)
    (set-pixel-blue! pix blue)))

(define pixel->string
  (lambda (pix)
    (string-append (number->string (pixel-red pix))
		   " "
		   (number->string (pixel-green pix))
		   " "
		   (number->string (pixel-blue pix))
		   " ")))
