# Contributor: Sara <sara at archlinux dot us>
# Maintainer: aksr <aksr at t-com dot me>
pkgname=fbpad-git
pkgver=0.r269.dbf1a4f
pkgrel=1
pkgdesc="A small linux framebuffer virtual terminal."
arch=('i686' 'x86_64')
url="http://repo.or.cz/w/fbpad.git"
license=('custom:BSD')
groups=()
depends=('tmux' 'vim')
makedepends=('git' 'ft2tf' 'ttf-fantasque-sans' 'ttf-droid' 'ttf-symbola')
optdepends=()
provides=('fbpad')
conflicts=('fbpad')
replaces=()
backup=()
options=()
install=$pkgname.install
source=(
    "$pkgname::git://repo.or.cz/fbpad.git"
    'conf.h'
    'fbpad-256.info'
    'LICENSE'
    'correct_term_and_simplify.patch'
    '0001-Support-both-bold-and-italics-at-same-time.patch'
)
noextract=()

pkgver() {
  cd $srcdir/$pkgname
  printf "0.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd $srcdir/$pkgname
  ## Custom conf.h
  msg "Applying exec patch"
  patch -Np1 -i "${srcdir}/correct_term_and_simplify.patch"

  msg "Applying bold italics patch"
  patch -Np1 -i "${srcdir}/0001-Support-both-bold-and-italics-at-same-time.patch"
  cp "$srcdir/conf.h" conf.h
}

build() {
  cd $srcdir/$pkgname
  make
}

package() {
  cd $srcdir/$pkgname
  install -Dm755 $srcdir/$pkgname/fbpad $pkgdir/usr/bin/fbpad
  install -Dm644 $srcdir/$pkgname/README $pkgdir/usr/share/doc/$pkgname/README
  install -Dm644 $srcdir/LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE

  ## Compile terminfo
  mkdir -p $pkgdir/usr/share/terminfo
  tic -x -o $pkgdir/usr/share/terminfo $srcdir/fbpad-256.info

  ## Setup fonts
  msg "Making normal font"
  ft2tf \
    /usr/share/fonts/TTF/FantasqueSansMono-Regular.ttf:4.5 \
    /usr/share/fonts/TTF/DroidSansFallbackFull.ttf:4.5 \
    /usr/share/fonts/TTF/Symbola.ttf:4.5 > "$srcdir/font.ttf"

  msg "Making italic font"
  ft2tf \
    /usr/share/fonts/TTF/FantasqueSansMono-Italic.ttf:4.5 \
    /usr/share/fonts/TTF/DroidSansFallbackFull.ttf:4.5 \
    /usr/share/fonts/TTF/Symbola.ttf:4.5 > "$srcdir/fonti.ttf"

  msg "Making bold font"
  ft2tf \
    /usr/share/fonts/TTF/FantasqueSansMono-Bold.ttf:4.5 \
    /usr/share/fonts/TTF/DroidSansFallbackFull.ttf:4.5 \
    /usr/share/fonts/TTF/Symbola.ttf:4.5 > "$srcdir/fontb.ttf"

  msg "Making bold italic font"
  ft2tf \
    /usr/share/fonts/TTF/FantasqueSansMono-BoldItalic.ttf:4.5 \
    /usr/share/fonts/TTF/DroidSansFallbackFull.ttf:4.5 \
    /usr/share/fonts/TTF/Symbola.ttf:4.5 > "$srcdir/fontbi.ttf"

  ## Install fonts
  install -Dm644 $srcdir/font.ttf  $pkgdir/usr/share/$pkgname/font.ttf
  install -Dm644 $srcdir/fonti.ttf $pkgdir/usr/share/$pkgname/fonti.ttf
  install -Dm644 $srcdir/fontb.ttf $pkgdir/usr/share/$pkgname/fontb.ttf
  install -Dm644 $srcdir/fontbi.ttf $pkgdir/usr/share/$pkgname/fontbi.ttf
}

sha256sums=('SKIP'
            'ede918abb2e0d85c6618bd6af92f191695557e22ae84d5f534fdc42608a4e1ad'
            '424cfd0acad2c27ef49d60a6fcc9d32a7fc121caa44e94a6b2c20c8268c69695'
            '0ea8d51c57a3a59ca57428b6fe9b47fdb1fde281fc1b095c9832872e85b09a72'
            '369d14a61c1b616138d03e54447b659fe03ee33abd8e593c581b50eb285c75b5'
            'd7754ec41ebec2b6560cc53990bac9b097bd549df7dbcf5b004e80d50204a30c')
