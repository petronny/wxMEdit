                      ==================================
                                wxMEdit v3.2RC
                      ==================================
About:
-----
wxMEdit is a cross-platform Text/Hex Editor written in C++ & wxWidgets.
wxMEdit is an improved version of MadEdit which has been discontinued.
wxMEdit supports many useful functions, e.g. Bookmark, Syntax Highlightings, 
Word Wraps, Encodings, Column/Hex Modes, Updates checking.
In HexMode, wxMEdit can open large files which size is up to 32GB (INT_MAX*16).


Supported Platforms:
-------------------
A. Linux, BSDes, macOS, OpenIndiana, other Unix-like OSes and Haiku OS (__WXGTK__):
   a. GNU C++ 3.x or higher OR clang++ 2.8 or higher:
      Required Tools and Libraries for building:
      1. autoconf 2.63 or higher (optional)
      2. automake 1.11.1 or higher (optional)
      3. wxWidgets 2.8/3.0/3.2 with Unicode enabled
      4. Boost 1.53.0 or higher
      5. ICU4C 50 or higher
      6. libcurl 7.15.5 or higher

B. Windows / ReactOS / Wine (__WXMSW__):
   a. MinGW/MinGW-w64 GNU C++ 3.x or higher:
      Required Tools and Libraries for building:
      1. Bakefile 0.2.9~0.2.11
      2. wxWidgets 2.8/3.0/3.2 with Unicode enabled
      3. Boost 1.53.0 or higher
      4. ICU4C 50 or higher
      5. libcurl 7.15.5 or higher

   b. Visual C++ 2005/2008/2010~2022 (by upgrading from 2008 solution and project files):
      Required Tools and Libraries for building:
      1. Bakefile 0.2.9~0.2.11
      2. wxWidgets 2.8/3.0/3.2 with Unicode enabled
      3. Boost 1.53.0 or higher
      4. ICU4C 50 or higher
      5. libcurl 7.15.5 or higher

NOTE:
   You can download Bakefile at:
      https://bakefile.org/#old-version

Syntax files, Locale files and Settings:
---------------------------------------
  Syntax files: in the path $(wxMEditConfigPath)/syntax/
  Locale files: in the path $(wxMEditConfigPath)/locale/
  
  $(wxMEditConfigPath) are the one of below paths:
    1. wxMEdit execution file directory under Windows and Unix-like OS.
    2. $(HOME)/.wxmedit/ under Unix-like OS.
    3. $(PREFIX)/share/wxmedit/ under Unix-like OS.
    4. %APPDATA%\wxmedit\ under Windows accroding to settings.
  
  If wxMEdit does not find any files in those paths, 
  wxMEdit can also execute standalone by using default settings.
  
  When quit wxMEdit, wxMEdit will save the settings to:
    1. $(HOME)/.wxmedit/wxmedit.cfg under Unix-like OS.
    2. %APPDATA%\wxmedit\ or $(wxMEdit execution file directory)/wxmedit.cfg under Windows accroding to settings.
  And FontWidth.dat will also be saved to the same path.
  FontWidth.dat is Cache of Font-Width-Data, it can speed-up wxMEdit a lot.


ChangeLog:
----------
wxMEdit v3.2RC (v3.1.0.90):
  1. added new feature: show file size in human readable format.
  2. added a option that always use certain encoding to open files.
  3. added GTK+ 3 and Wayland support.
  4. added High DPI supoport under Windows.
  5. redisigned the icons by jerome KASPER <neon.king.fr[at]gmail.com>.
  6. updated Unicode block descriptions for Unicode 15.0 (require ICU 72 or higher).
  7. fixed crash in text mode when a line exceed the limit of line length.
  8. fixed crash when pressing OK button in "About wxMEdit" window.
  9. fixed not responding when warping by window with text containing some tab characters.
 10. fixed broken triple click behavior in wxMEdit 3.1.
 11. fixed that the height of Information Window in MadEdit/wxMEdit (built with wxMSW-2.8) always reduce by 4.
 12. fixed fonts and encodings not restored after restart.
 13. fixed that cannot type characters via AltGr key.
 14. fixed cursor and selection rendering under Linux.
 15. fixed that IME candidate window doesn't follow the caret under Windows 10.
 16. added French translation by jerome KASPER <neon.king.fr[at]gmail.com>.
 17. updated Simplified Chinese translation.
 18. other minor changes and bug fixes.

wxMEdit v3.1:
  1. added a killer feature: word boundary with Chinese/Japanese/Thai/Lao/Khmer and Burmese characters etc.
  2. added a killer feature: word-wrap meet the Unicode® Standard Annex `#14`: Unicode Line Breaking Algorithm.
  3. added new feature: column align.
  4. added toolbar icon & shortcut for Inserting Ordered Sequence.
  5. changed End-of-Line mark patterns.
  6. updated Unicode block descriptions for Unicode 8.0 (require ICU 56 or higher).
  7. fixed incorrect word boundary with non-English characters when selecting word.
  8. fixed incorrect word-wrap with non-English letters.
  9. fixed broken characters input with numpad in wxMEdit that built with wxWidgets-3.0 GTK2.
 10. fixed incorrect behavior of when Ctrl-Backspace pressed at beginning of a text file OR at zero-width selection in column mode.
 11. fixed that cannot select the whole word wraped in different lines by double-click.
 12. fixed that triple-click cannot select a whole wrapped line.
 13. fixed that files are not keep in hex mode after restart & restore.
 14. fixed newline redundance when copying in regular text mode.
 15. updated Spanish translation by Carlos Sánchez <carlos1994sanchez[at]gmail.com>.
 16. updated Japanese translation by Tilt <tiltstr[at]gmail.com>.
 17. updated Simplified Chinese translation.
 18. updated Traditional Chinese translation by Vincent_TW.
 19. updated Russian translation by Будинов Станислав <stabud[at]yandex.ru>.
 20. other minor changes and bug fixes.

wxMEdit v3.0:
  1. added a killer feature: Inserting Ordered Sequence.
  2. added new options to display/print bookmark independent of line number.
  3. added a option whether enable dot matching new-line in regular expression.
  4. added a feature that show searching message in status bar when Search/Replace Dialog is invisible.
  5. improved bookmark appearance for displaying and printing.
  6. improved Tab and EOF mark pattern, make it easy to distinguish Tab mark from space mark.
  7. fixed that there are too few characters limited in a line with certain word wrap settings.
  8. fixed that width of list items in Syntax Highlighting Settings Dialog are not updated on resizing.
  9. fixed not responding when counting/replacing-all any zero-length assertions.
 10. updated Unicode block descriptions for Unicode 7.0 (require ICU 54 or higher).
 11. added German translation by Ronny Steiner <post[at]sirsteiner.de>.
 12. added Polish translation by Adam Massalski <massaada[at]wp.pl>.
 13. updated Simplified Chinese translation.
 14. updated Spanish translation by Carlos Sánchez <carlos1994sanchez[at]gmail.com>.
 15. updated Japanese translation by Tilt <tiltstr[at]gmail.com>.
 16. other minor changes and bug fixes.

See file ChangeLog for more changes.


License:
-------
wxMEdit is released under the GNU General Public License Version 3
or (at your option) any later version.


Authors:
------
JiaYanwei <wxmedit[at]gmail.com>          (current maintainer of wxMEdit)
jerome KASPER <neon.king.fr[at]gmail.com> (current maintainer of wxMEdit)
Alston Chen <madedit[at]gmail.com>        (creator of MadEdit)


Links:
-----
wxMEdit: https://wxmedit.github.io/
MadEdit: https://sourceforge.net/projects/madedit/
wxWidgets: https://www.wxwidgets.org/
Boost: https://www.boost.org/
ICU: https://icu.unicode.org/
Bakefile: https://bakefile.org/#old-version
Code::Blocks: https://www.codeblocks.org/
wxSmith: https://wiki.codeblocks.org/index.php?title=WxSmith_plugin
cURL: https://curl.se/
JLH fonts: https://jlhfonts.blogspot.com/
