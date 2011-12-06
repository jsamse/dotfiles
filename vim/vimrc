call pathogen#runtime_append_all_bundles()
call pathogen#helptags()

syntax enable

filetype plugin on
filetype indent on

colorscheme desert

set list
set listchars=tab:▸\ ,eol:¬
set showbreak=…

set sw=2
set tabstop=2
set expandtab
set number

set guifont=Monospace\ 8

map <F2> :NERDTreeToggle<CR>

" tab navigation like firefox
nmap <C-h> :tabp<CR>
nmap <C-l> :tabn<CR>

noremap <Left>  <NOP>
inoremap <Left>  <NOP>
noremap <Right> <NOP>
inoremap <Right> <NOP>
noremap <Up>    <NOP>
inoremap <Up>    <NOP>
noremap <Down>  <NOP>
inoremap <Down>  <NOP>

" :inoremap <Esc>   <NOP>
" :inoremap kj <Esc>

"
" Custom Highlights
"
highlight NonText guifg=#909090
highlight SpecialKey guifg=#909090

let g:ackprg="ack-grep -H --nocolor --nogroup --column"

let mapleader = ","

"
" Set some default stuff that allows for better integration
"
set encoding=utf-8
set scrolloff=3
set autoindent
set showmode
set showcmd
set hidden
set wildmenu
set wildmode=list:longest
set visualbell
set cursorline
set ttyfast
set ruler
set backspace=indent,eol,start
set laststatus=2


"
" Improve search
"
nnoremap / /\v
vnoremap / /\v
set ignorecase
set smartcase
set gdefault
set incsearch
set showmatch
set hlsearch
nnoremap <leader><space> :noh<CR>
nnoremap <tab> %
vnoremap <tab> %

"
"Make line wrapping act sanely
"
set wrap
set textwidth=79
set formatoptions=qrn1
set colorcolumn=85
set wildignore+=**/.svn
set wildignore+=*.class
set wildignore+=**/tmp

"
" Features only exists in 7.3
"
if v:version >= 703
  set undofile
  set relativenumber
endif

function! SetupJava()
  set path=src/main/java,src/test/java,$JAVA_HOME/src
  set suffixesadd=.java
endfunction

function! SetupPython()
  nmap <leader>d :!pydoc <cfile><CR>
  nmap <leader>x :!python %<CR>
  set suffixesadd=.py
endfunction

if has("autocmd")
  " do all autocmd stuff here
  " autocmd FileType javascript <cmd>
  autocmd BufNewFile,BufRead *.java :call SetupJava()
  autocmd BufNewFile,BufRead *.py :call SetupPython()
endif
