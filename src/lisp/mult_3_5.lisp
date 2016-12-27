; Sums all the numbers divisible by ;
; 3 or 5 up to 1000 ;
; Project Euler: 1 ;

(defvar sum 0)

(defun check (i) 
	"Checks whether is divisible by 3 or 5"
	(if (or (= (mod i 3) 0) (= (mod i 5) 0))
		; Increment sum by i ;
		(incf sum i)
	)
)

; Main function ;
(loop for i from 0 to 999 
	do(check i)
)

(print sum)
