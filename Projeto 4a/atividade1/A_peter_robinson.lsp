; Maria Eduarda Guedes Alves

(defun A(m n)
  (cond
    ((and (>= m 0) (>= n 0))
      (cond
        ((= m 0) (+ n 1))
        ((and (> m 0) (= n 0)) 
          (A (- m 1) 1))
        ((and (> m 0) (> n 0))
          (A (- m 1) (A m (- n 1))))
      )
    )
  (t (format t "ERRO!"))
  )
)

(defun main()
  (let ((i 5) (m 0) (n 0) (r 0))
    (loop while (< m i) do
      (loop while (< n i) do
        (setq r (A m n))
        (format t "A(~d, ~d): ~d~%" m n r)
        (setq n (+ n 1))
      )  
      (setq m (+ m 1))
      (setq n 0)
    )    
  )
  
  (print "fim")
)

(main)
