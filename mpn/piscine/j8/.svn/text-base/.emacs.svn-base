;;
;; .emacs for env in std_env
;; 
;; Made by Nicolas Sadirac
;; Login   <rn@epita>
;; 
;; Started on  Sat Oct 16 12:48:04 1993 Nicolas Sadirac
;; Last update Thu Oct  7 08:16:38 1999 Nicolas Sadirac
;;

(load-file "/usr/site/share/emacs/site-lisp/std_comment.el")
(load-file "/usr/site/share/emacs/site-lisp/div.el")

;;
;; bindings
;;
(global-set-key "" 'backward-delete-char)
(global-set-key "" 'compile)
(global-set-key "" 'goto-line)
(global-set-key "h" 'update-std-header)
(global-set-key "" 'do_insert_time)
(global-set-key "" 'std-file-header)

;;
;; special setings
;;
(setq smtpmail-local-domain "epita.fr")
(setq c-argdecl-indent 0)
(put 'eval-expression 'disabled nil)
(iso-accents-mode t)
(standard-display-european t)
;;
;; load our
;;

(if (file-exists-p "~/.myemacs")
    (load-file "~/.myemacs"))
