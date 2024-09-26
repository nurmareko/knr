;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname reverse) (read-case-sensitive #t) (teachpacks ((lib "batch-io.rkt" "teachpack" "2htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "batch-io.rkt" "teachpack" "2htdp")) #f)))
; [List-of x] -> [List-of x]
; reverse the given list.

(check-expect (reverse* '()) '())
(check-expect (reverse* (explode "abc")) (explode "cba"))
(check-expect (reverse* (explode "hello world")) (explode "dlrow olleh"))

(define (reverse* l)
  (cond
    [(empty? l) '()]
    [else
     (append (reverse* (rest l))
             (list (first l)))]))

;(define (reverse* l)
;  (cond
;    [(empty? l) ...]
;    [else
;     (... (first l) ...
;      ... (reverse* (rest l)) ...)]))