color koehler
syntax on
filetype plugin indent on
set number
nnoremap <F2> :set nonumber!<CR>:set foldcolumn=0<CR>
autocmd FileType python set complete+=k~/.vim/syntax/python.vim isk+=.,(
