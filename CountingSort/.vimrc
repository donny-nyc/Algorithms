" VIM Configuration File
" Description: helpful settings for C/C++ development
" Author: Donny

" set UTF-8 encoding
set encoding=utf-8
set fileencoding=utf-8
set termencoding=utf-8

" disable vi compatibility
set nocompatible

" follow indentation from previous line
set autoindent

" follow c-style indentation rules
set cindent

" configure tabwidth and use spaces instead of /t
set tabstop=4
set shiftwidth=4
set expandtab

" wrap lines
set textwidth=80

" syntax highlighting
set t_co=1024
syntax on
colorscheme pablo

" line numbers
set number

" highlight closing brace
set showmatch

" mappings
nmap <F2> :w<CR>
imap <F2> <ESC>:w<CR>i

" make
" set makeprg=cmake
map <F7> :make<CR>
map <S-F7> :make clean all<CR>

au BufNewFile,BufRead *.tpp set filetype=cpp
