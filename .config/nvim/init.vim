filetype plugin on
syntax on
set background=dark
set linebreak
set showmatch
set enc=utf-8
set hlsearch
set scrolloff=5
set cursorline
set autoindent
set shiftwidth=4
set tabstop=4
set smartindent
set smarttab
set mouse=a
set number relativenumber
colo myOblivion
set termguicolors
set bo=all
set showcmd


call plug#begin('~/.config/nvim/data')
Plug 'SirVer/ultisnips'
call plug#end()

let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<c-l>"
let g:UltiSnipsJumpBackwardTrigger="<c-h>"

inoremap <C-SPACE>	<Esc>l
nnoremap <C-SPACE>	i

inoremap {			{}<Left>
inoremap {<CR>		{<CR><Tab><CR>}<Up><Right>
inoremap <expr> }  	strpart(getline('.'), col('.')-1, 1) == "}" ? "\<Right>" : "}"

inoremap (			()<Left>
inoremap <expr> )  	strpart(getline('.'), col('.')-1, 1) == ")" ? "\<Right>" : ")"

inoremap [			[]<Left>
inoremap <expr> ]  	strpart(getline('.'), col('.')-1, 1) == "]" ? "\<Right>" : "]"

