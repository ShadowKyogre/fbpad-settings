# Contributor: Sara <sara at archlinux dot us>
# Maintainer: aksr <aksr at t-com dot me>
pkgname=fbpad-git
pkgver=0.r261.d11a8ba
pkgrel=1
pkgdesc="A small linux framebuffer virtual terminal."
arch=('i686' 'x86_64')
url="http://repo.or.cz/w/fbpad.git"
license=('custom:BSD')
groups=()
depends=('fish' 'vim')
makedepends=('git' 'ft2tf' 'ttf-fantasque-sans' 'ttf-droid')
optdepends=()
provides=('fbpad')
conflicts=('fbpad')
replaces=()
backup=()
options=()
install=$pkgname.install
source=(
    "$pkgname::git://repo.or.cz/fbpad.git"
    'config.h'
    'fbpad-256.info'
    'LICENSE'
    'correct_term.patch'
    'dont_desat.patch'
)
noextract=()
md5sums=('SKIP'
         'fb4c419e7a2d5c2d360864626d96c090'
         '185b9d6ec1c539213226a3e2509c7ccd'
         'ec67f29a7dec10f86ef31515ed657a91'
         '308c2e57d08b6c686596f80627e23282'
         '54ba0719a3f2714741748995d4372404')
sha1sums=('SKIP'
          'e3b82187d698e8542bbd556b311a49f3104bf203'
          'dbb816fe37faf0acb4e1a916d7493787c2b647fc'
          '76a535243054e1fdd9caaa46a1571cd381d74353'
          '7a7f20dca0e7deaa9afba2bb44e235c1eeb4fcb5'
          '7641cd6a9014c3a59feb7367bb6268046c65609b')
sha256sums=('SKIP'
            '3dff82c183d3d4734da0e63cd9df754d0007abf19381167ec2d00df0d7a072ed'
            'fb8ae049aa7d41fb285cbf7aa4487b28014273ebcfceefb4d58fb07018312e9c'
            '0ea8d51c57a3a59ca57428b6fe9b47fdb1fde281fc1b095c9832872e85b09a72'
            'b6d2df2198fc0312f29fc142c4f508c6244e0624b039c6ac006dc13f87b6a073'
            'c9859be2bae57086e05e63124ab179649870c9de9af8c2e98fe20f99ec334bad')

pkgver() {
  cd $srcdir/$pkgname
  printf "0.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd $srcdir/$pkgname
  ## Custom config.h
  cp $srcdir/config.h config.h
  patch -Np1 -i "${srcdir}/correct_term.patch"
  patch -Np1 -i "${srcdir}/dont_desat.patch"
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

  ft2tf /usr/share/fonts/TTF/FantasqueSansMono-Regular.ttf:4.5 /usr/share/fonts/TTF/DroidSansFallbackFull.ttf:4.5 > "$srcdir/font.ttf"
  ft2tf /usr/share/fonts/TTF/FantasqueSansMono-Italic.ttf:4.5 /usr/share/fonts/TTF/DroidSansFallbackFull.ttf:4.5 > "$srcdir/fonti.ttf"
  ft2tf /usr/share/fonts/TTF/FantasqueSansMono-Bold.ttf:4.5 /usr/share/fonts/TTF/DroidSansFallbackFull.ttf:4.5 > "$srcdir/fontb.ttf"
  ## Install fonts
  install -Dm644 $srcdir/font.ttf  $pkgdir/usr/share/$pkgname/font.ttf
  install -Dm644 $srcdir/fonti.ttf $pkgdir/usr/share/$pkgname/fonti.ttf
  install -Dm644 $srcdir/fontb.ttf $pkgdir/usr/share/$pkgname/fontb.ttf
}

