;;org->md
(add-to-list 'load-path "~/.emacs.d/site-lisp/ox-qmd")
(require 'ox-qmd)

;;markdown-mode
(add-to-list 'auto-mode-alist '("\\.md\\'" . markdown-mode))
