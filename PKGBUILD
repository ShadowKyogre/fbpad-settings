# Contributor: Sara <sara at archlinux dot us>
# Maintainer: aksr <aksr at t-com dot me>
pkgname=fbpad-git
pkgver=0.r267.421ceaa
pkgrel=2
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
    '0001-Restore-color-shifting-when-bold-isn-t-available.patch'
)
noextract=()
md5sums=('SKIP'
         '771ab33f50d49a344698a982312caf67'
         '185b9d6ec1c539213226a3e2509c7ccd'
         'ec67f29a7dec10f86ef31515ed657a91'
         '294755ab93d5ace4bc8c1a220935e202'
         '1bca5357ab00d20fd7f37c50cc0cb873')
sha1sums=('SKIP'
          '8e7029a0c5b2e597490688749dd5dbbe31189859'
          'dbb816fe37faf0acb4e1a916d7493787c2b647fc'
          '76a535243054e1fdd9caaa46a1571cd381d74353'
          '616012dadb1c7c984d7230a78e358fb9a991a3c3'
          'a512a992fcad53a0ac9213ab21449e45f50e26ab')
sha256sums=('SKIP'
            '2a49a6ab68a376ea43965219b60b5ec5b6296a96631c6fb11d07974adb078139'
            'fb8ae049aa7d41fb285cbf7aa4487b28014273ebcfceefb4d58fb07018312e9c'
            '0ea8d51c57a3a59ca57428b6fe9b47fdb1fde281fc1b095c9832872e85b09a72'
            '369d14a61c1b616138d03e54447b659fe03ee33abd8e593c581b50eb285c75b5'
            '83ae5d7d04494010786c98ce062c0cdb09fa9180e99e0ed0350b94bb27bb1e3d')

pkgver() {
  cd $srcdir/$pkgname
  printf "0.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd $srcdir/$pkgname
  ## Custom conf.h
  msg "Applying exec patch"
  patch -Np1 -i "${srcdir}/correct_term_and_simplify.patch"
  msg "Applying bold shift patch"
  patch -Np1 -i "${srcdir}/0001-Restore-color-shifting-when-bold-isn-t-available.patch"
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

  ## Install fonts
  install -Dm644 $srcdir/font.ttf  $pkgdir/usr/share/$pkgname/font.ttf
  install -Dm644 $srcdir/fonti.ttf $pkgdir/usr/share/$pkgname/fonti.ttf
  install -Dm644 $srcdir/fontb.ttf $pkgdir/usr/share/$pkgname/fontb.ttf
}

