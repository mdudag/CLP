; Maria Eduarda Guedes Alves

(defun ack(m n p)
  (cond
    ((and (>= m 0) (>= n 0) (>= p 0))
      (cond
        ((= p 0) (+ m n))
        ((and (= n 0) (= p 1)) 0)
        ((and (= n 0) (= p 2)) 1)
        ((> p 2) p)
        ((and (> n 0) (> p 0)) 
          (ack m (ack m (- n 1) p) (- p 1)))
      )
    )
  (t (format t "ERRO!"))
  )
)

(defun main()
  (let ((i 8) (m 0) (n 0) (p 0) (r 0))
    (loop while (< m i) do
      (loop while (< n i) do
        (loop while (< p i) do
          (setq r (ack m n p))
          (format t "ack(~d, ~d, ~d): ~d~%" m n p r)
          (setq p (+ p 1))
        )
        (setq n (+ n 1))
        (setq p 0)
      )  
      (setq m (+ m 1))
      (setq n 0)
    )    
  )
)

(main)
