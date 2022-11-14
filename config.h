/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int swallowfloating    = 0;
static const char *fonts[]          = { "JetBrains Mono NF:style=medium:size=11" };
static const char dmenufont[]       = "JetBrains Mono NF:style=medium:size=11";
// gruvbox
static const char fg[]              = "#ebdbb2";
static const char bg_normal[]       = "#3c3836";
static const char dr_normal[]       = "#282828";
static const char bg_selected[]     = "#504945";
static const char dr_selected[]     = "#928374";
// normal
//static const char fg[]              = "#ffffff";
//static const char bg_normal[]       = "#1e1e1e";
//static const char dr_normal[]       = "#1e1e1e";
//static const char bg_selected[]     = "#12488b";
//static const char dr_selected[]     = "#12488b";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { fg, bg_normal, dr_normal },
	[SchemeSel]  = { fg, bg_selected, dr_selected },
};

static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* tagging */
static const char *tags[] = { "!", "@", "#", "$", "%", "^", "&", "*", "(" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "zoom",     NULL,       NULL,       0,            1,           -1 },
  { "Mars",     NULL,       NULL,       0,            1,           -1 },
  { "Engrampa", NULL,       NULL,       0,            1,           -1 },
  { "chatterino",NULL,      NULL,       0,            1,           -1 },
  { "Wiimmfi-RPC v1.7.5",NULL,NULL,     0,            1,           -1 },
  { "minecraft-launcher",NULL,NULL,     0,            1,           -1 },
  { "nitrogen", NULL,       NULL,       0,            1,           -1 },
  { "Galculator",NULL,      NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
};

/* key definitions */
// Mod4Mask is super
// Mod1Mask is alt/meta
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[]       = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg_normal, "-nf", fg, "-sb", bg_selected, "-sf", fg, NULL };
static const char *dmenucmd[]       = { "dmenu_run_history", "-m", dmenumon, "-fn", dmenufont, "-nb", bg_normal, "-nf", fg, "-sb", bg_selected, "-sf", fg, NULL };
static const char *termcmd[]        = { "spawn-alacritty.sh", NULL };
static const char *brightnessup[]   = { "brightness-up.sh", NULL };
static const char *brightnessdown[] = { "brightness-down.sh", NULL };
static const char *screenshooter[]  = { "screenshot.sh", NULL };
static const char *volup[]          = { "volup.sh", NULL };
static const char *voldown[]        = { "voldown.sh", NULL };
//static const char *firefox[]        = { "firefox-bin", NULL };
static const char *firefox[]        = { "librewolf-bin", NULL };
static const char *slock[]          = { "slock", NULL };
static const char *playpause[]      = { "playerctl", "play-pause", NULL };
static const char *next[]           = { "f9.sh", NULL };
static const char *previous[]       = { "playerctl", "previous", NULL };
static const char *keepass[]        = { "keepassxc", NULL };
static const char *quitconf[]       = { "quitconf", dmenumon, bg_normal, fg, fg, NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
  { MODKEY|ShiftMask,             XK_f,      spawn,          {.v = firefox } },
  { MODKEY|ShiftMask,             XK_Escape, spawn,          {.v = slock } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.02} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.02} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
  { MODKEY,                       XK_F4,     spawn,          {.v = brightnessup } },
  { MODKEY,                       XK_F3,     spawn,          {.v = brightnessdown } },
  { MODKEY,                       XK_Print,  spawn,          {.v = screenshooter } },
  { MODKEY,                       XK_F10,    spawn,          {.v = voldown } },
  { MODKEY,                       XK_F11,    spawn,          {.v = volup } },
  { MODKEY,                       XK_F7,     spawn,          {.v = previous } },
  { MODKEY,                       XK_F8,     spawn,          {.v = playpause } },
  { MODKEY,                       XK_F9,     spawn,          {.v = next } },
  { MODKEY|ShiftMask,             XK_k,      spawn,          {.v = keepass } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_BackSpace,      spawn,           {.v = quitconf} },
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

