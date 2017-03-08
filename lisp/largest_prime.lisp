;; Find the largest prime factor of
;; 600851475143

;; Project Euler: 3

(defconstant MAXIMUM 600851475143) (defvar largest 0)

(defun isPrime (n)
        (and (> n 1) 
                (or (= n 2) (oddp n))
                (loop for i from 3 to (isqrt n) by 2
                never (zerop (rem n i)))
        )
)        

(defun main ()
        (loop for i from 0 to MAXIMUM
                (if (isPrime i)
                        (setq largest i)
                )
        )
)

(main)        
