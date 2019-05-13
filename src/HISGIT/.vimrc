set nu
set ruler
set cursorline
set spell spelllang=en_us
set autoread
set wildmenu
set wildmode=longest:list,full
filetype indent on
set autoindent
syntax enable
set tabstop=4
set hlsearch
nnoremap <F5> <Esc>:w<CR>:!gcc % -o /tmp/a.out<CR>
nnoremap <F7> <Esc>:w<CR>:!gcc % -o a.out<CR>
