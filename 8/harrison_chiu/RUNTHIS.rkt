#lang racket

(require "rags/base.rkt")

(define img (make-image 100 100 255))

(define warp
  (case-lambda 
    ((img)
     (warp img 0))
    ((img count)
     (if (< count (* (image-rows img)
		     (image-cols img)))
	 (let ((val (remainder count (image-rows img))))
	   (vector-set! (image-pixels img) count (make-pixel val val val))
	   (warp img (+ count 1)))
	 img))))

(warp img)

(write-image! img "pic.ppm")
