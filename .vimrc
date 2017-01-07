" A vimrc file.

" When started as "evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
  finish
endif

" Use Vim settings, rather than Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file
endif
set history=50		" keep 50 lines of command line history
set ruler	    	" show the cursor position all the time
set showcmd	    	" display incomplete commands
set incsearch		" do incremental searching
set number
set tabstop=4		"show existing tab with 4 spaces width
set expandtab
set shiftwidth=4
set cursorline      "highlight the current line

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" CTRL-U in insert mode deletes a lot.  Use CTRL-G u to first break undo,
" so that you can undo CTRL-U after inserting a line break.
inoremap <C-U> <C-G>u<C-U>

" In many terminal emulators the mouse works just fine, thus enable it.
if has('mouse')
  set mouse=a
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

set background=light
colorscheme desert 
" Only do this part when compiled with support for autocommands.
if has("autocmd")

  " Enable file type detection.
  " Use the default filetype settings, so that mail gets 'tw' set to 72,
  " 'cindent' is on in C files, etc.
  " Also load indent files, to automatically do language-dependent indenting.
  filetype plugin indent on

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd FileType text setlocal textwidth=78

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  " Also don't do it when the mark is in the first line, that is the default
  " position when opening a file.
  autocmd BufReadPost *
    \ if line("'\"") > 1 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

  augroup END

else

  set autoindent		" always set autoindenting on

endif " has("autocmd")

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
" Only define it when not defined already.
if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r ++edit # | 0d_ | diffthis
		  \ | wincmd p | diffthis
endif


" The setup for vim-MATLAB
runtime macros/matchit.vim
" source $VIMRUNTIME/macros/matchit.vim
" matlab vim
" integration of mlint code checker with :make command
autocmd BufEnter *.m  compiler mlint
" use F5 to run .m file
au FileType matlab map <buffer> <silent> <F5> :w<CR>:!matlab -nodesktop -nosplash -r "try, run(which('%')), end, quit" <CR><CR>
au FileType matlab set foldmethod=syntax foldcolumn=2 foldlevel=33


" The setup for vim-Octave
""autocmd FileType octave setlocal keywordprg=xterm\ -e\ info\ octave\ --vi-keys\ --index-search
"augroup filetypedetect
"		au! BufRead,BufNewFile *.m,*.oct set filetype=octave
"augroup END

" Powerline statusline
set rtp+=/usr/local/lib/python3.4/dist-packages/powerline/bindings/vim/
" Always show statusline
set laststatus=2
" Use 256 colors
set t_Co=256


