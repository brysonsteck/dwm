/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Roboto:size=14", "emoji:size=14" };
static const char dmenufont[]       = "Roboto:size=14";
static const char col_turquoise[]   = "#00776C";
static const char col_black[]       = "#000000";
static const char col_black_border[] = "#101010";
static const char col_gray1[]       = "#222222";
static const char col_gray1_5[]     = "#333333";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_nord0[]       = "#2e3440";
static const char col_nord1[]       = "#3b4252";
static const char col_nord2[]       = "#434c5e";
static const char col_nord3[]       = "#4c566a";
static const char col_nord4[]       = "#d8dee9";
static const char col_nord10[]      = "#5e81ac";
static const char col_white1[]      = "#DBDBDD";
static const char col_white2[]      = "#FFFFFF";
static const char col_purple1[]     = "#02060F";
static const char col_purple2[]     = "#0D0224";
static const char col_blue[]        = "#144982";
static const char col_blue2[]       = "#143968";
static const char col_orange[]      = "#F59549";
static const char col_other[]       = "#191C21";
static const char col_yellow[]      = "#D3AD66";
static const char col_warm_white[]  = "#DCD6B8";
static const unsigned int gappx     = 6;
/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab			= showtab_auto;        /* Default tab bar show mode */
static const int toptab				= False;               /* False means bottom tab bar */

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_nord4, col_black, col_black_border },
	[SchemeSel]  = { col_nord4, col_gray1,  col_blue  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "zoom",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
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
	{ "t",      tile },    /* first entry is default */
	{ "f",      NULL },    /* no layout function means floating behavior */
	{ "m",      monocle },
};

/* key definitions */
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
static const char *dmenucmd[] = { "dmenu_run_history", "-b", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_gray3, "-sb", col_blue, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "spawn-alacritty.sh", NULL };
static const char *brightnessup[]    = { "brightness-up", NULL };
static const char *brightnessdown[]  = { "brightness-down", NULL };
static const char *screenshooter[]   = { "xfce4-screenshooter", NULL };
static const char *volup[]           = { "volup.sh", NULL };
static const char *voldown[]         = { "voldown.sh", NULL };
static const char *volmute[]         = { "volmute.sh", NULL };
static const char *firefox[]         = { "firefox", "--new-window", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_f,      spawn,          {.v = firefox } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_w,      tabmode,        {-1} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_F4,     spawn,          {.v = brightnessup } },
    { MODKEY,                       XK_F3,     spawn,          {.v = brightnessdown } },
    { MODKEY,                       XK_Print,  spawn,          {.v = screenshooter } },
    { MODKEY,                       XK_F9,     spawn,          {.v = volmute } },
    { MODKEY,                       XK_F10,    spawn,          {.v = voldown } },
    { MODKEY,                       XK_F11,    spawn,          {.v = volup } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_BackSpace,      quit,           {0} },
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
	{ ClkTabBar,            0,              Button1,        focuswin,       {0} },
};

