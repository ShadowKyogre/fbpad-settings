# Contributor: Sara <sara at archlinux dot us>
# Maintainer: aksr <aksr at t-com dot me>
pkgname=fbpad-git
pkgver=0.r265.886bccb
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
    '0001-Allow-specifying-truecolors-with-escape-codes.patch'
)
noextract=()
md5sums=('SKIP'
         'SKIP'
         '185b9d6ec1c539213226a3e2509c7ccd'
         'ec67f29a7dec10f86ef31515ed657a91'
         '294755ab93d5ace4bc8c1a220935e202'
         'f2d4f0caa734fe9c8b50776621e458b5')
sha1sums=('SKIP'
          'SKIP'
          'dbb816fe37faf0acb4e1a916d7493787c2b647fc'
          '76a535243054e1fdd9caaa46a1571cd381d74353'
          '616012dadb1c7c984d7230a78e358fb9a991a3c3'
          '5e0ae64ffb995b1b59853f487c2d0bcc4b00b601')
sha256sums=('SKIP'
            'SKIP'
            'fb8ae049aa7d41fb285cbf7aa4487b28014273ebcfceefb4d58fb07018312e9c'
            '0ea8d51c57a3a59ca57428b6fe9b47fdb1fde281fc1b095c9832872e85b09a72'
            '369d14a61c1b616138d03e54447b659fe03ee33abd8e593c581b50eb285c75b5'
            '6af6794094ed79c438b457bd6357b5d2b5a9165c8c8c6473095894c23a6f6776')

pkgver() {
  cd $srcdir/$pkgname
  printf "0.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd $srcdir/$pkgname
  ## Custom conf.h
  cp "$srcdir/conf.h" conf.h
  patch -Np1 -i "${srcdir}/correct_term_and_simplify.patch"
  patch -Np1 -i "${srcdir}/0001-Allow-specifying-truecolors-with-escape-codes.patch"
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

  ## Install fonts
  install -Dm644 $srcdir/font.ttf  $pkgdir/usr/share/$pkgname/font.ttf
  install -Dm644 $srcdir/fonti.ttf $pkgdir/usr/share/$pkgname/fonti.ttf
  install -Dm644 $srcdir/fontb.ttf $pkgdir/usr/share/$pkgname/fontb.ttf
}

