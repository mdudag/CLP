; Maria Eduarda Guedes Alves

(defun insertionSort (L)
  (labels ; Define uma função dentro de outra
    ((insere (pivo L-ordenada)
      (cond 
        ((null L-ordenada) (list pivo))
        ((<= pivo (car L-ordenada)) (cons pivo L-ordenada))
        (t (cons (car L-ordenada) (insere pivo (rest L-ordenada))))
      )
    ))

    (if (null L) nil
      (let ((L-ordenando (list (car L))))
        (dolist (elemento (cdr L) L-ordenando)
          (setf L-ordenando (insere elemento L-ordenando))
        )
      )
    )

  )
)
