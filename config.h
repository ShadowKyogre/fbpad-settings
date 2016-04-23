/* framebuffer device */
#define FBDEV		"/dev/fb0"

/* list of tags */
#define TAGS		"xnlhtr01uiva-"
#define TAGS_SAVED	""

/* programs mapped to m-c, m-m, m-e */
#define SHELL		{"fish"}
#define EDITOR		{"vim"}
#define MAIL		{"mutt"}

/* fbval_t should match framebuffer depth */
typedef unsigned int fbval_t;

/* tinyfont files for regular, italic, and bold fonts */
#define FR		"/usr/share/fbpad-git/font.ttf"
#define FI		"/usr/share/fbpad-git/fonti.ttf"
#define FB		"/usr/share/fbpad-git/fontb.ttf"

/* foreground and background colors */
#define FGCOLOR		15
#define BGCOLOR		0

/* where to write the screen shot */
#define SCRSHOT		"/tmp/scr"

/* lock command password; NULL disables locking */
#define PASS		NULL

/* optimized version of fb_val() */
#define FB_VAL(r, g, b)	fb_val((r), (g), (b))

#define COLOR0 0x0d0815
#define COLOR1 0xbf0053
#define COLOR2 0x53bf00
#define COLOR3 0xbf6c00
#define COLOR4 0x0053bf
#define COLOR5 0x6c00bf
#define COLOR6 0x00bf6c
#define COLOR7 0xacc0cd
#define COLOR8 0x30233a
#define COLOR9 0xff62a6
#define COLOR10 0xa6ff62
#define COLOR11 0xffbb62
#define COLOR12 0x62a6ff
#define COLOR13 0xbb62ff
#define COLOR14 0x62ffbb
#define COLOR15 0xdcd6c2
