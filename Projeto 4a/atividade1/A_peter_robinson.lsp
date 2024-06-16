; Maria Eduarda Guedes Alves

(defun A(m n)
  (cond
    ((= m 0) (+ n 1))
    ((and (> m 0) (= n 0)) 
      (A (- m 1) 1))
    ((and (> m 0) (> n 0))
      (A (- m 1) (A m (- n 1))))
    (t (format t "ERRO!"))
  )
)

; Exemplo de Consulta: (format t "A(2, 1) = ~d~%" (A 2 1))
