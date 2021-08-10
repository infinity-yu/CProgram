"高亮当前行
set cursorline
"光标移动到buffer的顶部和底部时保持三行距离
set scrolloff=3
"忽略大小写检索
set ignorecase
"输入检索时动态变化
set incsearch
"检索高亮
set hlsearch
"设置无响铃
set novisualbell
"语法高亮
syntax enable
syntax on
"自动拆分行
set linebreak
"共享剪贴板
set clipboard=unnamed
"不建立备份
set nobackup

"允许backspace和光标键跨行边界
set whichwrap+=<,>,h,l
"在处理未保存或只读文件时，弹出确认
set confirm
"高亮显示匹配的括号
set showmatch


" 你在此设置运行时路径
set rtp+=~/.vim/bundle/Vundle.vim

call vundle#begin()

" 在这里面输入安装的插件
" Vundle 本身就是一个插件
Plugin 'gmarik/Vundle.vim'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'


"所有插件都应该在这一行之前
call vundle#end()

" filetype off
filetype plugin indent on

" 把这几句配置加到函数外面任意地方：
" @airline
set t_Co=256      "在windows中用xshell连接打开vim可以显示色彩
let g:airline#extensions#tabline#enabled = 1   " 是否打开tabline
"这个是安装字体后 必须设置此项"
let g:airline_powerline_fonts = 1
set laststatus=2  "永远显示状态栏
let g:airline_theme='bubblegum' "选择主题
let g:airline#extensions#tabline#enabled=1    "Smarter tab line: 显示窗口tab和buffer
"let g:airline#extensions#tabline#left_sep = ' '  "separater
"let g:airline#extensions#tabline#left_alt_sep = '|'  "separater
"let g:airline#extensions#tabline#formatter = 'default'  "formater
let g:airline_left_sep = '>>>'
let g:airline_left_alt_sep = '->'
let g:airline_right_sep = '<<<'
let g:airline_right_alt_sep = '<-'




set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab "/ expandtab
set cuc
set cul
set nu
syntax on
syntax enable
colorscheme desert

" Indent
set smartindent
set cindent
set autoindent

" TagList
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1

" WinManager
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

" Omnicompletion
set nocp
filetype plugin indent on
set completeopt=longest,menu

nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>

autocmd BufNewFile *.[ch],*.hpp,*.cpp exec ":call SetTitle()" 

"加入注释
func SetComment()
	 call setline(1,"/*===============================================================") 
	 call append(line("."),   "*   Copyright (C) ".strftime("%Y")." All rights reserved.")
	 call append(line(".")+1, "*   ") 
	 call append(line(".")+2, "*   文件名称：".expand("%:t")) 
	 call append(line(".")+3, "*   创 建 者：YQQ")
	 call append(line(".")+4, "*   创建日期：".strftime("%Y年%m月%d日")) 
	 call append(line(".")+5, "*   描    述：") 
	 call append(line(".")+6, "*")
	 call append(line(".")+7, "*   更新日志：") 
	 call append(line(".")+8, "*") 
	 call append(line(".")+9, "================================================================*/") 
endfunc

"定义函数SetTitle，自动插入文件头 
func SetTitle()
	 call SetComment()
	 if expand("%:e") == 'hpp' 
		 call append(line(".")+10, "#ifndef _".toupper(expand("%:t:r"))."_H") 
		 call append(line(".")+11, "#define _".toupper(expand("%:t:r"))."_H") 
		 call append(line(".")+12, "#ifdef __cplusplus") 
		 call append(line(".")+13, "extern \"C\"") 
		 call append(line(".")+14, "{") 
		 call append(line(".")+15, "#endif") 
		 call append(line(".")+16, "") 
		 call append(line(".")+17, "#ifdef __cplusplus") 
		 call append(line(".")+18, "}") 
		 call append(line(".")+19, "#endif") 
		 call append(line(".")+20, "#endif //".toupper(expand("%:t:r"))."_H") 
	 elseif expand("%:e") == 'h' 
		 call append(line(".")+10, "#endif") 
		 call append(line(".")+10, "") 
		 call append(line(".")+10, "#ifndef _".toupper(expand("%:t:r"))."_H") 
		 call append(line(".")+11, "#define _".toupper(expand("%:t:r"))."_H") 
	 elseif &filetype == 'c' 
		 call append(line(".")+10,"#include \<strings.h\>") 
		 call append(line(".")+10,"#include \<stdlib.h\>") 
		 call append(line(".")+10,"#include \<string.h\>") 
		 call append(line(".")+10,"#include \<stdio.h\>") 
	 elseif &filetype == 'cpp' 
		 call append(line(".")+10,"#include \<iostream\>") 
		 call append(line(".")+11,"using namespace std;") 
	 endif
	 "新建文件后，自动定位到文件末尾
    autocmd BufNewFile * normal G
endfunc

set mouse=a

