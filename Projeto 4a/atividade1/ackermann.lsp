; Maria Eduarda Guedes Alves

(defun ack(m n p)
  (cond
    ((= p 0) (+ m n))
    ((and (> m 0) (= n 0) (= p 1)) 0)
    ((and (> m 0) (= n 0) (= p 2)) m)
    ((and (> m 0) (> n 0) (= p 2)) (expt m n))
    ((> p 2) p)
    ((and (> m 0) (> n 0) (> p 0)) 
      (ack m (ack m (- n 1) p) (- p 1)))
  (t (format t "ERRO!"))
  ))

; Exemplo de Consulta: (format t "Ack(2, 1, 0) = ~d~%" (ack 2 1 0))
