let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <S-Tab> <Plug>snipMateBack
inoremap <silent> <Plug>snipMateShow =snipMate#ShowAvailableSnips()
inoremap <silent> <Plug>snipMateBack =snipMate#BackwardsSnippet()
inoremap <silent> <Plug>snipMateTrigger =snipMate#TriggerSnippet(1)
inoremap <silent> <Plug>snipMateNextOrTrigger =snipMate#TriggerSnippet()
inoremap <silent> <SNR>41_AutoPairsReturn =AutoPairsReturn()
vmap  :CtrlPBuffer
nnoremap <silent>  :call comfortable_motion#flick(-200)
omap  :CtrlPBuffer
nnoremap <silent>  :call comfortable_motion#flick(100)
map  <Plug>(ctrlp)
map  h
xmap 	 <Plug>snipMateVisual
smap 	 <Plug>snipMateNextOrTrigger
xmap <NL> j
nmap <NL> j
snoremap <NL> i<Right>=snipMate#TriggerSnippet()
omap <NL> j
map  k
map  l
nmap  <Plug>yankstack_substitute_newer_paste
nmap  <Plug>yankstack_substitute_older_paste
xnoremap <silent>  :call multiple_cursors#new("v", 0)
nnoremap <silent>  :call multiple_cursors#new("n", 1)
nnoremap <silent>  :call comfortable_motion#flick(-100)
nnoremap  :call GotoFile("new")
nnoremap f :call GotoFile("new")
map   /
vnoremap <silent> # :call VisualSelection('', '')?=@/
vnoremap $e `>a"`<i"
vnoremap $q `>a'`<i'
vnoremap $$ `>a"`<i"
vnoremap $3 `>a}`<i{
vnoremap $2 `>a]`<i[
vnoremap $1 `>a)`<i(
vnoremap <silent> * :call VisualSelection('', '')/=@/
vmap + <Plug>(expand_region_expand)
nmap + <Plug>(expand_region_expand)
xmap 0 ^
nmap 0 ^
omap 0 ^
imap ½ $
cmap ½ $
imap Ð <Plug>yankstack_substitute_newer_paste
imap ð <Plug>yankstack_substitute_older_paste
xmap S <Plug>VSurround
vmap Si S(i_f)
nnoremap YY gg"+yG
nnoremap \<Right> L
nnoremap \<Left> H
nnoremap \<Down> J
nnoremap \<Up> K
map \p :cp
map \n :cn
map \co ggVGy:tabnew:set syntax=qfpgg
map \cc :botright cope
vnoremap <silent> \r :call VisualSelection('replace', '')
map \g :Ack 
map \e :e! ~/.vim_runtime/my_configs.vim
nnoremap <silent> \d :GitGutterToggle
nmap <silent> \a <Plug>(ale_next_wrap)
nnoremap <silent> \z :Goyo
map \nf :NERDTreeFind
map \nb :NERDTreeFromBookmark 
map \nn :NERDTreeToggle
map \j :CtrlP
map \f :MRU
map \o :BufExplorer
map \pp :setlocal paste!
map \x :e ~/buffer.md
map \q :e ~/buffer
noremap \m mmHmt:%s///ge'tzt'm
map \s? z=
map \sa zg
map \sp [s
map \sn ]s
map \ss :setlocal spell!
map \cd :cd %:p:h:pwd
map \te :tabedit =expand("%:p:h")/
nmap \tl :exe "tabn ".g:lasttab
map \t\ :tabnext 
map \tm :tabmove 
map \tc :tabclose
map \to :tabonly
map \tn :tabnew
map \h :bprevious
map \l :bnext
map \ba :bufdo bd
map \bd :Bclose:tabclosegT
map <silent> \ :noh
nmap \w :w!
nmap _ <Plug>(expand_region_shrink)
xmap _ <Plug>(expand_region_shrink)
omap a/ <Plug>(textobj-lastpat-n)
xmap a/ <Plug>(textobj-lastpat-n)
omap a? <Plug>(textobj-lastpat-N)
xmap a? <Plug>(textobj-lastpat-N)
omap ac <Plug>(textobj-character-ac)
xmap ac <Plug>(textobj-character-ac)
nmap cS <Plug>CSurround
nmap cs <Plug>Csurround
nmap cr <Plug>Coerce
nmap ds <Plug>Dsurround
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
xmap gS <Plug>VgSurround
xnoremap <silent> gó :call multiple_cursors#select_all("v", 0)
nnoremap <silent> gó :call multiple_cursors#select_all("n", 0)
xnoremap <silent> g :call multiple_cursors#new("v", 0)
nnoremap <silent> g :call multiple_cursors#new("n", 0)
nmap gcu <Plug>Commentary<Plug>Commentary
nmap gcc <Plug>CommentaryLine
omap gc <Plug>Commentary
nmap gc <Plug>Commentary
xmap gc <Plug>Commentary
nnoremap gf :call GotoFile("")
vnoremap <silent> gv :call VisualSelection('gv', '')
omap i/ <Plug>(textobj-lastpat-n)
xmap i/ <Plug>(textobj-lastpat-n)
omap i? <Plug>(textobj-lastpat-N)
xmap i? <Plug>(textobj-lastpat-N)
omap ic <Plug>(textobj-character-ac)
xmap ic <Plug>(textobj-character-ac)
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
nnoremap <SNR>122_: :=v:count ? v:count : ''
nnoremap <SNR>115_: :=v:count ? v:count : ''
smap <S-Tab> <Plug>snipMateBack
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
nnoremap <silent> <Plug>SurroundRepeat .
snoremap <silent> <Plug>snipMateBack a=snipMate#BackwardsSnippet()
snoremap <silent> <Plug>snipMateNextOrTrigger a=snipMate#TriggerSnippet()
nnoremap <silent> <Plug>GitGutterPreviewHunk :GitGutterPreviewHunk
nnoremap <silent> <Plug>GitGutterUndoHunk :GitGutterUndoHunk
nnoremap <silent> <Plug>GitGutterStageHunk :GitGutterStageHunk
nnoremap <silent> <expr> <Plug>GitGutterPrevHunk &diff ? '[c' : ":\execute v:count1 . 'GitGutterPrevHunk'\"
nnoremap <silent> <expr> <Plug>GitGutterNextHunk &diff ? ']c' : ":\execute v:count1 . 'GitGutterNextHunk'\"
xnoremap <silent> <Plug>GitGutterTextObjectOuterVisual :call gitgutter#hunk#text_object(0)
xnoremap <silent> <Plug>GitGutterTextObjectInnerVisual :call gitgutter#hunk#text_object(1)
onoremap <silent> <Plug>GitGutterTextObjectOuterPending :call gitgutter#hunk#text_object(0)
onoremap <silent> <Plug>GitGutterTextObjectInnerPending :call gitgutter#hunk#text_object(1)
xnoremap <silent> <Plug>(expand_region_shrink) :call expand_region#next('v', '-')
xnoremap <silent> <Plug>(expand_region_expand) :call expand_region#next('v', '+')
nnoremap <silent> <Plug>(expand_region_expand) :call expand_region#next('n', '+')
nmap <silent> <Plug>CommentaryUndo :echoerr "Change your <Plug>CommentaryUndo map to <Plug>Commentary<Plug>Commentary"
nnoremap <silent> <Plug>(ctrlp) :CtrlP
nnoremap <silent> <Plug>(ale_hover) :ALEHover
nnoremap <silent> <Plug>(ale_find_references) :ALEFindReferences
nnoremap <silent> <Plug>(ale_go_to_definition_in_tab) :ALEGoToDefinitionInTab
nnoremap <silent> <Plug>(ale_go_to_definition) :ALEGoToDefinition
nnoremap <silent> <Plug>(ale_fix) :ALEFix
nnoremap <silent> <Plug>(ale_detail) :ALEDetail
nnoremap <silent> <Plug>(ale_lint) :ALELint
nnoremap <silent> <Plug>(ale_reset_buffer) :ALEResetBuffer
nnoremap <silent> <Plug>(ale_disable_buffer) :ALEDisableBuffer
nnoremap <silent> <Plug>(ale_enable_buffer) :ALEEnableBuffer
nnoremap <silent> <Plug>(ale_toggle_buffer) :ALEToggleBuffer
nnoremap <silent> <Plug>(ale_reset) :ALEReset
nnoremap <silent> <Plug>(ale_disable) :ALEDisable
nnoremap <silent> <Plug>(ale_enable) :ALEEnable
nnoremap <silent> <Plug>(ale_toggle) :ALEToggle
nnoremap <silent> <Plug>(ale_last) :ALELast
nnoremap <silent> <Plug>(ale_first) :ALEFirst
nnoremap <silent> <Plug>(ale_next_wrap) :ALENextWrap
nnoremap <silent> <Plug>(ale_next) :ALENext
nnoremap <silent> <Plug>(ale_previous_wrap) :ALEPreviousWrap
nnoremap <silent> <Plug>(ale_previous) :ALEPrevious
nnoremap <Right> l
nnoremap <Left> h
nnoremap <Down> j
nnoremap <Up> k
nnoremap <F6> :nohl
map <F9> :call CompileRunGcc()
map <C-Space> ?
cnoremap  <Home>
cnoremap  <End>
imap S <Plug>ISurround
imap s <Plug>Isurround
imap 	 <Plug>snipMateNextOrTrigger
inoremap <NL> =snipMate#TriggerSnippet()
cnoremap  
cnoremap  <Down>
cnoremap  <Up>
imap 	 <Plug>snipMateShow
imap  <Plug>Isurround
inoremap $e ""i
inoremap $q ''i
inoremap $4 {o}O
inoremap $3 {}i
inoremap $2 []i
inoremap $1 ()i
cnoremap $q eDeleteTillSlash()
cnoremap $c e eCurrentFileDir("e")
cnoremap $j e ./
cnoremap $d e ~/Desktop/
cnoremap $h e ~/
map ½ $
xmap Ð <Plug>yankstack_substitute_newer_paste
nmap Ð <Plug>yankstack_substitute_newer_paste
xmap ð <Plug>yankstack_substitute_older_paste
nmap ð <Plug>yankstack_substitute_older_paste
xnoremap <silent> ó :call multiple_cursors#select_all("v", 0)
nnoremap <silent> ó :call multiple_cursors#select_all("n", 1)
vmap ë :m'<-2`>my`<mzgv`yo`z
vmap ê :m'>+`<my`>mzgv`yo`z
nmap ë mz:m-2`z
nmap ê mz:m+`z
map! <silent> \p <Plug>PeepOpen
iabbr xdate =strftime("%d/%m/%y %H:%M:%S")
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autoread
set background=dark
set backspace=eol,start,indent
set balloonexpr=ale#balloon#Expr()
set clipboard=autoselect,exclude:cons\\|linux,unnamed
set cmdheight=2
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set fileformats=unix,dos,mac
set grepprg=/bin/grep\ -nH
set guifont=IBM\ Plex\ Mono:h14,:Hack\ 14,Source\ Code\ Pro\ 12,Bitstream\ Vera\ Sans\ Mono\ 11
set guioptions=aegimtT
set helplang=en
set hidden
set history=500
set hlsearch
set ignorecase
set incsearch
set isfname=@,48-57,/,.,-,_,+,,,#,$,%,~,=,:
set langmenu=en
set laststatus=2
set lazyredraw
set matchtime=2
set nomodeline
set mouse=a
set operatorfunc=<SNR>74_go
set pastetoggle=<F5>
set printoptions=paper:a4
set ruler
set runtimepath=~/.vim_runtime/my_plugins/vim-textobj-lastpat,~/.vim_runtime/my_plugins/vim-textobj-user,~/.vim_runtime/sources_non_forked/ack.vim,~/.vim_runtime/sources_non_forked/ale,~/.vim_runtime/sources_non_forked/auto-pairs,~/.vim_runtime/sources_non_forked/bufexplorer,~/.vim_runtime/sources_non_forked/comfortable-motion.vim,~/.vim_runtime/sources_non_forked/ctrlp.vim,~/.vim_runtime/sources_non_forked/goyo.vim,~/.vim_runtime/sources_non_forked/gruvbox,~/.vim_runtime/sources_non_forked/lightline-ale,~/.vim_runtime/sources_non_forked/lightline.vim,~/.vim_runtime/sources_non_forked/mayansmoke,~/.vim_runtime/sources_non_forked/mru.vim,~/.vim_runtime/sources_non_forked/nerdtree,~/.vim_runtime/sources_non_forked/nginx.vim,~/.vim_runtime/sources_non_forked/open_file_under_cursor.vim,~/.vim_runtime/sources_non_forked/rust.vim,~/.vim_runtime/sources_non_forked/snipmate-snippets,~/.vim_runtime/sources_non_forked/tabular,~/.vim_runtime/sources_non_forked/tlib,~/.vim_runtime/sources_non_forked/vim-abolish,~/.vim_runtime/sources_non_forked/vim-addon-mw-utils,~/.vim_runtime/sources_non_forked/vim-bundle-mako,~/.vim_runtime/sources_non_forked/vim-coffee-script,~/.vim_runtime/sources_non_forked/vim-colors-solarized,~/.vim_runtime/sources_non_forked/vim-commentary,~/.vim_runtime/sources_non_forked/vim-expand-region,~/.vim_runtime/sources_non_forked/vim-flake8,~/.vim_runtime/sources_non_forked/vim-fugitive,~/.vim_runtime/sources_non_forked/vim-gitgutter,~/.vim_runtime/sources_non_forked/vim-go,~/.vim_runtime/sources_non_forked/vim-indent-object,~/.vim_runtime/sources_non_forked/vim-less,~/.vim_runtime/sources_non_forked/vim-markdown,~/.vim_runtime/sources_non_forked/vim-multiple-cursors,~/.vim_runtime/sources_non_forked/vim-pug,~/.vim_runtime/sources_non_forked/vim-pyte,~/.vim_runtime/sources_non_forked/vim-repeat,~/.vim_runtime/sources_non_forked/vim-snipmate,~/.vim_runtime/sources_non_forked/vim-snippets,~/.vim_runtime/sources_non_forked/vim-surround,~/.vim_runtime/sources_non_forked/vim-yankstack,~/.vim_runtime/sources_non_forked/vim-zenroom2,~/.vim_runtime/sources_forked/peaksea,~/.vim_runtime/sources_forked/set_tabline,~/.vim_runtime/sources_forked/vim-irblack-forked,~/.vim_runtime/sources_forked/vim-peepopen,~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim81,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after,~/.vim_runtime,~/.vim_runtime/sources_non_forked/vim-snipmate/after,~/.vim_runtime/sources_non_forked/vim-markdown/after,~/.vim_runtime/sources_non_forked/vim-less/after,~/.vim_runtime/sources_non_forked/vim-coffee-script/after,~/.vim_runtime/sources_non_forked/tabular/after,~/.vim_runtime/sources_non_forked/rust.vim/after,/usr/local/lib/python2.7/dist-packages/powerline/bindings/vim
set scrolloff=7
set shiftwidth=4
set showmatch
set showtabline=2
set smartcase
set smartindent
set smarttab
set statusline=%!py3eval('powerline.new_window()')
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set noswapfile
set switchbuf=useopen,usetab,newtab
set tabline=%!lightline#tabline()
set tabstop=4
set textwidth=500
set timeoutlen=500
set undodir=~/.vim_runtime/temp_dirs/undodir
set undofile
set whichwrap=b,s,<,>,h,l
set wildignore=*.o,*~,*.pyc,*/.git/*,*/.hg/*,*/.svn/*,*/.DS_Store
set wildmenu
set nowritebackup
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd /media/cjsoft/CJS/git-repos/HomeWork/oop/exp5/1/usingvirtual
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 main.cpp
badd +1 shape.cpp
badd +8 shape.h
badd +1 Makefile
argglobal
silent! argdel *
tabnew
tabnext -1
edit shape.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 61 + 92) / 185)
exe 'vert 2resize ' . ((&columns * 61 + 92) / 185)
exe 'vert 3resize ' . ((&columns * 61 + 92) / 185)
argglobal
let s:cpo_save=&cpo
set cpo&vim
inoremap <buffer> <silent> <BS> =AutoPairsDelete()
inoremap <buffer> <silent> § =AutoPairsMoveCharacter('''')
inoremap <buffer> <silent> ¢ =AutoPairsMoveCharacter('"')
inoremap <buffer> <silent> © =AutoPairsMoveCharacter(')')
inoremap <buffer> <silent> ¨ =AutoPairsMoveCharacter('(')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent> î :call AutoPairsJump()a
inoremap <buffer> <silent> <expr> ð AutoPairsToggle()
inoremap <buffer> <silent> â =AutoPairsBackInsert()
inoremap <buffer> <silent> å =AutoPairsFastWrap()
inoremap <buffer> <silent> ý =AutoPairsMoveCharacter('}')
inoremap <buffer> <silent> û =AutoPairsMoveCharacter('{')
inoremap <buffer> <silent> Ý =AutoPairsMoveCharacter(']')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent>  =AutoPairsDelete()
inoremap <buffer> <silent>   =AutoPairsSpace()
inoremap <buffer> <silent> " =AutoPairsInsert('"')
inoremap <buffer> <silent> ' =AutoPairsInsert('''')
inoremap <buffer> <silent> ( =AutoPairsInsert('(')
inoremap <buffer> <silent> ) =AutoPairsInsert(')')
noremap <buffer> <silent> î :call AutoPairsJump()
noremap <buffer> <silent> ð :call AutoPairsToggle()
inoremap <buffer> <silent> [ =AutoPairsInsert('[')
inoremap <buffer> <silent> ] =AutoPairsInsert(']')
inoremap <buffer> <silent> ` =AutoPairsInsert('`')
inoremap <buffer> <silent> { =AutoPairsInsert('{')
inoremap <buffer> <silent> } =AutoPairsInsert('}')
let &cpo=s:cpo_save
unlet s:cpo_save
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'cpp'
setlocal filetype=cpp
endif
setlocal fixendofline
set foldcolumn=1
setlocal foldcolumn=1
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal nomodeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal signcolumn=auto
setlocal smartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%{lightline#link()}%#LightlineLeft_inactive_0#%(\ %t\ %)%#LightlineLeft_inactive_0_1#\ %#LightlineMiddle_inactive#%=%#LightlineRight_inactive_1_2#\ %#LightlineRight_inactive_1#%(\ %3p%%\ %)%#LightlineRight_inactive_0_1#\ %#LightlineRight_inactive_0#%(\ %3l:%-2v\ %)
setlocal suffixesadd=
setlocal noswapfile
setlocal synmaxcol=3000
if &syntax != 'cpp'
setlocal syntax=cpp
endif
setlocal tabstop=4
setlocal tagcase=
setlocal tags=
setlocal termwinkey=
setlocal termwinscroll=10000
setlocal termwinsize=
setlocal textwidth=500
setlocal thesaurus=
setlocal undofile
setlocal undolevels=-123456
setlocal varsofttabstop=
setlocal vartabstop=
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 8 - ((7 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
8
normal! 0
wincmd w
argglobal
if bufexists('shape.cpp') | buffer shape.cpp | else | edit shape.cpp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <buffer> <silent> <BS> =AutoPairsDelete()
inoremap <buffer> <silent> § =AutoPairsMoveCharacter('''')
inoremap <buffer> <silent> ¢ =AutoPairsMoveCharacter('"')
inoremap <buffer> <silent> © =AutoPairsMoveCharacter(')')
inoremap <buffer> <silent> ¨ =AutoPairsMoveCharacter('(')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent> î :call AutoPairsJump()a
inoremap <buffer> <silent> <expr> ð AutoPairsToggle()
inoremap <buffer> <silent> â =AutoPairsBackInsert()
inoremap <buffer> <silent> å =AutoPairsFastWrap()
inoremap <buffer> <silent> ý =AutoPairsMoveCharacter('}')
inoremap <buffer> <silent> û =AutoPairsMoveCharacter('{')
inoremap <buffer> <silent> Ý =AutoPairsMoveCharacter(']')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent>  =AutoPairsDelete()
inoremap <buffer> <silent>   =AutoPairsSpace()
inoremap <buffer> <silent> " =AutoPairsInsert('"')
inoremap <buffer> <silent> ' =AutoPairsInsert('''')
inoremap <buffer> <silent> ( =AutoPairsInsert('(')
inoremap <buffer> <silent> ) =AutoPairsInsert(')')
noremap <buffer> <silent> î :call AutoPairsJump()
noremap <buffer> <silent> ð :call AutoPairsToggle()
inoremap <buffer> <silent> [ =AutoPairsInsert('[')
inoremap <buffer> <silent> ] =AutoPairsInsert(']')
inoremap <buffer> <silent> ` =AutoPairsInsert('`')
inoremap <buffer> <silent> { =AutoPairsInsert('{')
inoremap <buffer> <silent> } =AutoPairsInsert('}')
let &cpo=s:cpo_save
unlet s:cpo_save
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'cpp'
setlocal filetype=cpp
endif
setlocal fixendofline
set foldcolumn=1
setlocal foldcolumn=1
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal nomodeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal signcolumn=auto
setlocal smartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%{lightline#link()}%#LightlineLeft_active_0#%(\ %{lightline#mode()}\ %)%{(&paste)?\"\ \":\"\"}%(\ %{&paste?\"PASTE\":\"\"}\ %)%#LightlineLeft_active_0_1#\ %#LightlineLeft_active_1#%(\ %{exists(\"*fugitive#head\")?fugitive#head():\"\"}\ %)%{((exists(\"*fugitive#head\")\ &&\ \"\"!=fugitive#head()))&&(((&filetype!=\"help\"&&\ &readonly))||1||((&filetype!=\"help\"&&(&modified||!&modifiable))))?\"\ \":\"\"}%(\ %{&filetype==\"help\"?\"\":&readonly?\"🔒\":\"\"}\ %)%{((&filetype!=\"help\"&&\ &readonly))&&(1||((&filetype!=\"help\"&&(&modified||!&modifiable))))?\"\ \":\"\"}%(\ %t\ %)%{((&filetype!=\"help\"&&(&modified||!&modifiable)))?\"\ \":\"\"}%(\ %{&filetype==\"help\"?\"\":&modified?\"+\":&modifiable?\"\":\"-\"}\ %)%#LightlineLeft_active_1_2#\ %#LightlineMiddle_active#%=%#LightlineRight_active_1_2#\ %#LightlineRight_active_1#%(\ %3p%%\ %)%#LightlineRight_active_0_1#\ %#LightlineRight_active_0#%(\ %3l:%-2v\ %)
setlocal suffixesadd=
setlocal noswapfile
setlocal synmaxcol=3000
if &syntax != 'cpp'
setlocal syntax=cpp
endif
setlocal tabstop=4
setlocal tagcase=
setlocal tags=
setlocal termwinkey=
setlocal termwinscroll=10000
setlocal termwinsize=
setlocal textwidth=500
setlocal thesaurus=
setlocal undofile
setlocal undolevels=-123456
setlocal varsofttabstop=
setlocal vartabstop=
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 71 - ((11 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
71
normal! 05|
wincmd w
argglobal
if bufexists('main.cpp') | buffer main.cpp | else | edit main.cpp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <buffer> <silent> <BS> =AutoPairsDelete()
inoremap <buffer> <silent> § =AutoPairsMoveCharacter('''')
inoremap <buffer> <silent> ¢ =AutoPairsMoveCharacter('"')
inoremap <buffer> <silent> © =AutoPairsMoveCharacter(')')
inoremap <buffer> <silent> ¨ =AutoPairsMoveCharacter('(')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent> î :call AutoPairsJump()a
inoremap <buffer> <silent> <expr> ð AutoPairsToggle()
inoremap <buffer> <silent> â =AutoPairsBackInsert()
inoremap <buffer> <silent> å =AutoPairsFastWrap()
inoremap <buffer> <silent> ý =AutoPairsMoveCharacter('}')
inoremap <buffer> <silent> û =AutoPairsMoveCharacter('{')
inoremap <buffer> <silent> Ý =AutoPairsMoveCharacter(']')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent>  =AutoPairsDelete()
inoremap <buffer> <silent>   =AutoPairsSpace()
inoremap <buffer> <silent> " =AutoPairsInsert('"')
inoremap <buffer> <silent> ' =AutoPairsInsert('''')
inoremap <buffer> <silent> ( =AutoPairsInsert('(')
inoremap <buffer> <silent> ) =AutoPairsInsert(')')
noremap <buffer> <silent> î :call AutoPairsJump()
noremap <buffer> <silent> ð :call AutoPairsToggle()
inoremap <buffer> <silent> [ =AutoPairsInsert('[')
inoremap <buffer> <silent> ] =AutoPairsInsert(']')
inoremap <buffer> <silent> ` =AutoPairsInsert('`')
inoremap <buffer> <silent> { =AutoPairsInsert('{')
inoremap <buffer> <silent> } =AutoPairsInsert('}')
let &cpo=s:cpo_save
unlet s:cpo_save
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'cpp'
setlocal filetype=cpp
endif
setlocal fixendofline
set foldcolumn=1
setlocal foldcolumn=1
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal nomodeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal signcolumn=auto
setlocal smartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%{lightline#link()}%#LightlineLeft_inactive_0#%(\ %t\ %)%#LightlineLeft_inactive_0_1#\ %#LightlineMiddle_inactive#%=%#LightlineRight_inactive_1_2#\ %#LightlineRight_inactive_1#%(\ %3p%%\ %)%#LightlineRight_inactive_0_1#\ %#LightlineRight_inactive_0#%(\ %3l:%-2v\ %)
setlocal suffixesadd=
setlocal noswapfile
setlocal synmaxcol=3000
if &syntax != 'cpp'
setlocal syntax=cpp
endif
setlocal tabstop=4
setlocal tagcase=
setlocal tags=
setlocal termwinkey=
setlocal termwinscroll=10000
setlocal termwinsize=
setlocal textwidth=500
setlocal thesaurus=
setlocal undofile
setlocal undolevels=-123456
setlocal varsofttabstop=
setlocal vartabstop=
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 12 - ((11 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
12
normal! 0
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 61 + 92) / 185)
exe 'vert 2resize ' . ((&columns * 61 + 92) / 185)
exe 'vert 3resize ' . ((&columns * 61 + 92) / 185)
tabnext
edit Makefile
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
let s:cpo_save=&cpo
set cpo&vim
inoremap <buffer> <silent> <BS> =AutoPairsDelete()
inoremap <buffer> <silent> § =AutoPairsMoveCharacter('''')
inoremap <buffer> <silent> ¢ =AutoPairsMoveCharacter('"')
inoremap <buffer> <silent> © =AutoPairsMoveCharacter(')')
inoremap <buffer> <silent> ¨ =AutoPairsMoveCharacter('(')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent> î :call AutoPairsJump()a
inoremap <buffer> <silent> <expr> ð AutoPairsToggle()
inoremap <buffer> <silent> â =AutoPairsBackInsert()
inoremap <buffer> <silent> å =AutoPairsFastWrap()
inoremap <buffer> <silent> ý =AutoPairsMoveCharacter('}')
inoremap <buffer> <silent> û =AutoPairsMoveCharacter('{')
inoremap <buffer> <silent> Ý =AutoPairsMoveCharacter(']')
inoremap <buffer> <silent> Û =AutoPairsMoveCharacter('[')
inoremap <buffer> <silent>  =AutoPairsDelete()
inoremap <buffer> <silent>   =AutoPairsSpace()
inoremap <buffer> <silent> " =AutoPairsInsert('"')
inoremap <buffer> <silent> ' =AutoPairsInsert('''')
inoremap <buffer> <silent> ( =AutoPairsInsert('(')
inoremap <buffer> <silent> ) =AutoPairsInsert(')')
noremap <buffer> <silent> î :call AutoPairsJump()
noremap <buffer> <silent> ð :call AutoPairsToggle()
inoremap <buffer> <silent> [ =AutoPairsInsert('[')
inoremap <buffer> <silent> ] =AutoPairsInsert(']')
inoremap <buffer> <silent> ` =AutoPairsInsert('`')
inoremap <buffer> <silent> { =AutoPairsInsert('{')
inoremap <buffer> <silent> } =AutoPairsInsert('}')
let &cpo=s:cpo_save
unlet s:cpo_save
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal nocindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:#\ -,mO:#\ \ ,b:#
setlocal commentstring=#\ %s
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal noexpandtab
if &filetype != 'make'
setlocal filetype=make
endif
setlocal fixendofline
set foldcolumn=1
setlocal foldcolumn=1
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=^\\s*include
setlocal includeexpr=
setlocal indentexpr=GetMakeIndent()
setlocal indentkeys=!^F,o,O,<:>,=else,=endif
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal nomodeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal signcolumn=auto
setlocal nosmartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%{lightline#link()}%#LightlineLeft_active_0#%(\ %{lightline#mode()}\ %)%{(&paste)?\"\ \":\"\"}%(\ %{&paste?\"PASTE\":\"\"}\ %)%#LightlineLeft_active_0_1#\ %#LightlineLeft_active_1#%(\ %{exists(\"*fugitive#head\")?fugitive#head():\"\"}\ %)%{((exists(\"*fugitive#head\")\ &&\ \"\"!=fugitive#head()))&&(((&filetype!=\"help\"&&\ &readonly))||1||((&filetype!=\"help\"&&(&modified||!&modifiable))))?\"\ \":\"\"}%(\ %{&filetype==\"help\"?\"\":&readonly?\"🔒\":\"\"}\ %)%{((&filetype!=\"help\"&&\ &readonly))&&(1||((&filetype!=\"help\"&&(&modified||!&modifiable))))?\"\ \":\"\"}%(\ %t\ %)%{((&filetype!=\"help\"&&(&modified||!&modifiable)))?\"\ \":\"\"}%(\ %{&filetype==\"help\"?\"\":&modified?\"+\":&modifiable?\"\":\"-\"}\ %)%#LightlineLeft_active_1_2#\ %#LightlineMiddle_active#%=%#LightlineRight_active_1_2#\ %#LightlineRight_active_1#%(\ %3p%%\ %)%#LightlineRight_active_0_1#\ %#LightlineRight_active_0#%(\ %3l:%-2v\ %)
setlocal suffixesadd=
setlocal noswapfile
setlocal synmaxcol=3000
if &syntax != 'make'
setlocal syntax=make
endif
setlocal tabstop=4
setlocal tagcase=
setlocal tags=
setlocal termwinkey=
setlocal termwinscroll=10000
setlocal termwinsize=
setlocal textwidth=500
setlocal thesaurus=
setlocal undofile
setlocal undolevels=-123456
setlocal varsofttabstop=
setlocal vartabstop=
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
