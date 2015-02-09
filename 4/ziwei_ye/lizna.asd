(asdf:defsystem #:lizna
  :description "NetPBM manipulator library"
  :author "Ziwei Ye"
  :license "who cares"
  :serial t
  :depends-on (#:split-sequence)
  :components ((:file "package")
	       (:file "magick")
               (:file "lizna")
	       (:file "transform")))

