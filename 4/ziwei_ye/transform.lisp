(in-package #:lizna)

(defun temp-crap-pic-maker (image)
  "quality code"
  (loop for y-val upto (- (bpm-y image) 1) do
       (loop for x-val upto (- (bpm-x image) 1)
	  for zzzzz-val = (random 225)
	  do (setf (aref (img-array image) y-val x-val) (make-array 3 :initial-contents `(,y-val ,x-val ,zzzzz-val)))))
  (loop for y-val upto (- (bpm-y image) 1)
     for x-val upto (- (bpm-x image) 1)
     for zzzzz-val = (+ (floor (+ y-val x-val) 3) (random 10))
     do (setf (aref (img-array image) y-val x-val) (make-array 3 :initial-contents '(255 255 255)))))

(defun make-a-very-crappy-image-that-is-my-first-computer-graphics-homework-10/10-literally-van-gogh-ign-11/10-with-rice-i-feel-violated-random-tumblr-user ()
  (let ((pic (new-image "P3" 225 225 "whatisthis")))
    (temp-crap-pic-maker pic)
    (save-image pic)))

(make-a-very-crappy-image-that-is-my-first-computer-graphics-homework-10/10-literally-van-gogh-ign-11/10-with-rice-i-feel-violated-random-tumblr-user)
