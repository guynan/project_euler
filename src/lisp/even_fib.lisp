;; Find the sum of all even numbers in
;; the Fibonacci sequence whose values
;; do not exceed 4 million. 

(defvar n0 1)
(defvar n1 1)
(defvar term 1)
(defvar sum 4)
(defconstant MAXIMUM 4000000)


(loop 
        (setq term (+ n0 n1))

        (when (> term MAXIMUM) (return sum))

        (if (evenp term)
                (setq sum (+ sum term))
        )

        (setq n0 n1)
        (setq n1 term)

)

(print sum)
