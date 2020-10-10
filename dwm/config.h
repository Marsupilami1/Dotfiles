/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const char *fonts[]          = { "FiraCode:size=9" };
static const char dmenufont[]       = "FiraCode:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#ff8000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  "#ff8000"  },
	[SchemeStatus] = { "#ffffff", "#32204a",  "#171a1b"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel] = { "#000000", "#e4d5b6",  "#16630c"  }, // Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeTagsNormP] = { "#ffffff", "#4a222a",  "#171a1b"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeTagsNormI] = { "#ffffff", "#123151",  "#171a1b"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel] = { "#d8e1e8", "#7b6896",  "#360746"  }, // infobar middle  selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm] = { "#ffffff", "#263238",  "#171a1b"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "feh",      NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "|M|",      centeredmaster },   /* first entry is default */
	{ "[]=",      tile },
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ ">M>",      centeredfloatingmaster },
	{ NULL, 	  NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-c", "-m", dmenumon, "-l", "20", "-bw", "1", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", "#000000", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *termtabcmd[]  = { "tabbed", "-c", "alacritty", "--embed", NULL };
static const char *filemgrcmd[]  = { "pcmanfm", NULL };
static const char *editcmd[]  = { "geany", NULL };
static const char *surfcmd[]  = { "tabbed", "-c", "surf", "-e", NULL };
static const char *frfxcmd[]  = { "firefox", NULL };
static const char *mathcmd[]  = { "/home/martin/myScripts/dmenuScripts/math_to_tex.sh", NULL };
static const char *emacscmd[] = { "emacsclient", "-create-frame", "--alternate-editor=''", NULL };

#include "movestack.c"
static Key keys[] = {
	/* modifier             key    function        argument */
	{ MODKEY,               33,    spawn,          {.v = dmenucmd } },// p
	{ MODKEY,               36,    spawn,          {.v = termcmd } }, // Return
	{ MODKEY,               22,    spawn,          {.v = termtabcmd } }, // BackSpace
	{ MODKEY|ShiftMask,     36,    spawn,          {.v = filemgrcmd } }, // Return
	{ MODKEY,               42,    spawn,          {.v = editcmd } }, // g
	{ MODKEY,               41,    spawn,          {.v = frfxcmd } }, // f
	{ MODKEY,               47,    spawn,          {.v = mathcmd } }, // m
	{ MODKEY,               39,    spawn,          {.v = surfcmd } }, // s
	{ MODKEY,               26,    spawn,          {.v = emacscmd } }, // e
	{ MODKEY,               56,    togglebar,      {0} },             // b
	{ MODKEY,               44,    focusstack,     {.i = +1 } },      // j
	{ MODKEY,               45,    focusstack,     {.i = -1 } },      // k
	{ MODKEY|ShiftMask,     44,    movestack,      {.i = +1 } },      // j
	{ MODKEY|ShiftMask,     45,    movestack,      {.i = -1 } },      // k
	{ MODKEY,               31,    incnmaster,     {.i = +1 } },      // i
	{ MODKEY,               40,    incnmaster,     {.i = -1 } },      // d
	{ MODKEY,               43,    setmfact,       {.f = -0.05} },    // h
	{ MODKEY,               46,    setmfact,       {.f = +0.05} },    // l
	{ MODKEY,               27,    reorganizetags, {0} },             // r
	{ MODKEY,               21,    setmequal,      {0} },             // =
	{ MODKEY,               25,    zoom,           {0} },             // z
	{ MODKEY,               23,    view,           {0} },             // Tab
	{ MODKEY|ShiftMask,     54,    killclient,     {0} },             // c
	{ MODKEY,               67,    setlayout,      {.v = &layouts[0]} }, // f1
	{ MODKEY,               68,    setlayout,      {.v = &layouts[1]} }, // f2
	{ MODKEY,               69,    setlayout,      {.v = &layouts[2]} }, // f3
	{ MODKEY,               70,    setlayout,      {.v = &layouts[3]} }, // f4
	{ MODKEY,               71,    setlayout,      {.v = &layouts[4]} }, // f5
	{ MODKEY,               87,    setlayout,      {.v = &layouts[0]} }, // num_1
	{ MODKEY,               88,    setlayout,      {.v = &layouts[1]} }, // num_2
	{ MODKEY,               89,    setlayout,      {.v = &layouts[2]} }, // num_3
	{ MODKEY,               83,    setlayout,      {.v = &layouts[3]} }, // num_4
	{ MODKEY,               84,    setlayout,      {.v = &layouts[4]} }, // num_5
	{ MODKEY|ControlMask,	30,    cyclelayout,    {.i = -1 } },	  // u
	{ MODKEY|ControlMask,	32,    cyclelayout,    {.i = +1 } },      // o
	{ MODKEY,               65,    setlayout,      {0} },             // space
	{ MODKEY|ShiftMask,     65,    togglefloating, {0} },             // space
	{ MODKEY,               19,    view,           {.ui = ~0 } },     // 0
	{ MODKEY|ShiftMask,     19,    tag,            {.ui = ~0 } },     // 0
	{ MODKEY,               30,    focusmon,       {.i = -1 } },      // u
	{ MODKEY,               32,    focusmon,       {.i = +1 } },      // o
	{ MODKEY|ShiftMask,     30,    tagmon,         {.i = -1 } },      // u
	{ MODKEY|ShiftMask,     32,    tagmon,         {.i = +1 } },      // o
	{ MODKEY,               113,   focusmon,       {.i = -1 } },      // left arrow
	{ MODKEY,               114,   focusmon,       {.i = +1 } },      // right arrow
	{ MODKEY|ShiftMask,     113,   tagmon,         {.i = -1 } },      // left arrow
	{ MODKEY|ShiftMask,     114,   tagmon,         {.i = +1 } },      // right arrow
	TAGKEYS(                10,                    0)                 // 1
	TAGKEYS(                11,                    1)                 // 2
	TAGKEYS(                12,                    2)                 // 3
	TAGKEYS(                13,                    3)                 // 4
	TAGKEYS(                14,                    4)                 // 5
	TAGKEYS(                15,                    5)                 // 6
	TAGKEYS(                16,                    6)                 // 7
	TAGKEYS(                17,                    7)                 // 8
	TAGKEYS(                18,                    8)                 // 9
	{ MODKEY|ShiftMask,     38,    quit,           {0} },             // q
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
