/*
  PS2Keyboard.h - PS2Keyboard library
  Copyright (c) 2007 Free Software Foundation.  All right reserved.
  Written by Christian Weichel <info@32leaves.net>

  ** Mostly rewritten Paul Stoffregen <paul@pjrc.com>, June 2010
  ** Modified for use with Arduino 13 by L. Abraham Smith, <n3bah@microcompdesign.com> * 
  ** Modified for easy interrup pin assignement on method begin(datapin,irq_pin). Cuningan <cuninganreset@gmail.com> **

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Version 2.4.sk001 (May 2015) BY きむ茶工房(きむしげ)
  - 日本語キーボード対応（ [右ALT]+[カナ/かな]キーでカタカナ入力モードに移行）
  - F4 key support from F1. Also change a little key code
  - We have removed German and French keyboard in order to save memory
  
  2021.05.05 modefied for K3NG Keyer BY 7M4MON.
  - K3NG Keyer向けにカスタマイズ
  * Ctrl or Alt の組み合わせを未使用のキーコードで送ることで設定変更や送信機切替などが出来るようになっている。
  * F4～F12 と Ctrl or Alt の組み合わせは非対応。
  * 「変換」キーで和文モード（かな刻印入力）に入る。
  * 「無変換」キーで欧文モード（アルファベット刻印入力）に戻る。
  * 和文モード中、「 ( 」 [Shift + 8] で一時的にアルファベット刻印入力となる。
  * 上記モード中、「 ) 」 [Shift + 9] で日本語刻印入力に戻る。
  * 和文モード中に数字を入力したいとき等は「英数」キーで何も送出せずにアルファベット刻印入力になる。
  * 「ひらがな」キーで日本語刻印入力に戻る。
  * UNICODEの文字入力は非対応にした。
  * 英語刻印<->日本語刻印は変換/無変換 で行うようにし、[右ALT]+[カナ/かな]キーでの切り替えは無効化

*/


#ifndef PS2Keyboard_h
#define PS2Keyboard_h

#define OPTION_PS2_KEYBOARD_JAPANESE
// #define OPTION_PS2_KEYBOARD_US
// #define OPTION_PS2_KEYBOARD_GERMAN
// #define OPTION_PS2_KEYBOARD_FRENCH

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h" // for attachInterrupt, FALLING
#else
#include "WProgram.h"
#endif

#include "utility/int_pins.h"




// Every call to read() returns a single byte for each
// keystroke.  These configure what byte will be returned
// for each "special" key.  To ignore a key, use zero.
#define PS2_TAB         9
#define PS2_ENTER       13
#define PS2_BACKSPACE   127
#define PS2_ESC         27
#define PS2_INSERT      128
#define PS2_DELETE      127
#define PS2_HOME        129
#define PS2_END         156
#define PS2_PAGEUP      25
#define PS2_PAGEDOWN    26
#define PS2_UPARROW     11
#define PS2_LEFTARROW   8
#define PS2_DOWNARROW   10
#define PS2_RIGHTARROW  21
#define PS2_F1          130
#define PS2_F2          131
#define PS2_F3          132
#define PS2_F4          133
#define PS2_F5          134
#define PS2_F6          135
#define PS2_F7          136
#define PS2_F8          137
#define PS2_F9          138
#define PS2_F10         139
#define PS2_F11         140
#define PS2_F12         141
#define PS2_SCROLL      142

#define PS2_F1_SHIFT          143
#define PS2_F2_SHIFT          144
#define PS2_F3_SHIFT          145
#define PS2_F4_SHIFT          146
#define PS2_F5_SHIFT          147
#define PS2_F6_SHIFT          148
#define PS2_F7_SHIFT          149
#define PS2_F8_SHIFT          150
#define PS2_F9_SHIFT          151
#define PS2_F10_SHIFT         152
#define PS2_F11_SHIFT         153
#define PS2_F12_SHIFT         154
#define PS2_TAB_SHIFT         9
#define PS2_ENTER_SHIFT       13
#define PS2_BACKSPACE_SHIFT   157

//#define PS2_KANA			0xA0		// カナ/かな
#define PS2_LEFT_ALT	158
//#define PS2_LEFT_CTRL	159
//#define PS2_SCROLL_SHIFT 160            //A0  使ってない

/*

check_ps2_keyboard
4266 ps2_prosign_flag

convert_cw_number_to_ascii
case 211222: mode_wabun = true;  return 162; break;  

case 162  : send_the_dits_and_dahs("-..---"); break;  // Start wabun mode "DO(ﾎﾚ)" ｢ 
*/

#ifdef OPTION_PS2_KEYBOARD_JAPANESE
#define PS2_KANA   160  // 0xA0		// カナ/かな
#define	PS2_A_CTRL	224
#define	PS2_B_CTRL	225
#define	PS2_C_CTRL	226
#define	PS2_D_CTRL	227
#define	PS2_E_CTRL	228
#define	PS2_F_CTRL	229
#define	PS2_G_CTRL	230
#define	PS2_H_CTRL	231
#define	PS2_I_CTRL	232
#define	PS2_J_CTRL	233
#define	PS2_K_CTRL	234
#define	PS2_L_CTRL	235
#define	PS2_M_CTRL	236
#define	PS2_N_CTRL	237
#define	PS2_O_CTRL	238
#define	PS2_P_CTRL	239
#define	PS2_Q_CTRL	240
#define	PS2_R_CTRL	241
#define	PS2_S_CTRL	242
#define	PS2_T_CTRL	243
#define	PS2_U_CTRL	244
#define	PS2_V_CTRL	245
#define	PS2_W_CTRL	246
#define	PS2_X_CTRL	247
#define	PS2_Y_CTRL	248
#define	PS2_Z_CTRL	249
#define	PS2_F1_CTRL	250
#define	PS2_F2_CTRL	251
#define	PS2_F3_CTRL	252
#define	PS2_F4_CTRL	0
#define	PS2_F5_CTRL	0
#define	PS2_F6_CTRL	0
#define	PS2_F7_CTRL	0
#define	PS2_F8_CTRL	0
#define	PS2_F9_CTRL	0
#define	PS2_F10_CTRL	0
#define	PS2_F11_CTRL	0
#define	PS2_F12_CTRL	0
#define	PS2_F1_ALT	253
#define	PS2_F2_ALT	254
#define	PS2_F3_ALT	255
#define	PS2_F4_ALT	0
#define	PS2_F5_ALT	0
#define	PS2_F6_ALT	0
#define	PS2_F7_ALT	0
#define	PS2_F8_ALT	0
#define	PS2_F9_ALT	0
#define	PS2_F10_ALT	0
#define	PS2_F11_ALT	0
#define	PS2_F12_ALT	0

#endif //OPTION_PS2_KEYBOARD_JAPANESE

#if defined(OPTION_PS2_KEYBOARD_US)
#define PS2_A_CTRL 162
#define PS2_B_CTRL 163
#define PS2_C_CTRL 164
#define PS2_D_CTRL 165
#define PS2_E_CTRL 166
#define PS2_F_CTRL 167
#define PS2_G_CTRL 168
#define PS2_H_CTRL 169
#define PS2_I_CTRL 170
#define PS2_J_CTRL 171
#define PS2_K_CTRL 172
#define PS2_L_CTRL 173
#define PS2_M_CTRL 174
#define PS2_N_CTRL 175
#define PS2_O_CTRL 176
#define PS2_P_CTRL 177
#define PS2_Q_CTRL 178
#define PS2_R_CTRL 179
#define PS2_S_CTRL 180
#define PS2_T_CTRL 181
#define PS2_U_CTRL 182
#define PS2_V_CTRL 183
#define PS2_W_CTRL 184
#define PS2_X_CTRL 185
#define PS2_Y_CTRL 186
#define PS2_Z_CTRL 187
#define PS2_F1_CTRL 188
#define PS2_F2_CTRL 189
#define PS2_F3_CTRL 190
#define PS2_F4_CTRL 191
#define PS2_F5_CTRL 192
#define PS2_F6_CTRL 193
#define PS2_F7_CTRL 194
#define PS2_F8_CTRL 195
#define PS2_F9_CTRL 196
#define PS2_F10_CTRL 197
#define PS2_F11_CTRL 198
#define PS2_F12_CTRL 199
#define PS2_F1_ALT 200
#define PS2_F2_ALT 201
#define PS2_F3_ALT 202
#define PS2_F4_ALT 203
#define PS2_F5_ALT 204
#define PS2_F6_ALT 205
#define PS2_F7_ALT 206
#define PS2_F8_ALT 207
#define PS2_F9_ALT 208
#define PS2_F10_ALT 209
#define PS2_F11_ALT 210
#define PS2_F12_ALT 211
#endif //OPTION_PS2_KEYBOARD_US


// ----------------- added K3NG

#if defined(OPTION_PS2_KEYBOARD_GERMAN)

#define PS2_A_CTRL 162
#define PS2_B_CTRL 163
#define PS2_C_CTRL 200 //164
#define PS2_D_CTRL 165
#define PS2_E_CTRL 166
#define PS2_F_CTRL 201 //167
#define PS2_G_CTRL 168
#define PS2_H_CTRL 169
#define PS2_I_CTRL 170
#define PS2_J_CTRL 171
#define PS2_K_CTRL 172
#define PS2_L_CTRL 173
#define PS2_M_CTRL 174
#define PS2_N_CTRL 175
#define PS2_O_CTRL 202 //176
#define PS2_P_CTRL 177
#define PS2_Q_CTRL 203 //178
#define PS2_R_CTRL 204 //179
#define PS2_S_CTRL 180
#define PS2_T_CTRL 205 //181
#define PS2_U_CTRL 182
#define PS2_V_CTRL 183
#define PS2_W_CTRL 184
#define PS2_X_CTRL 185
#define PS2_Y_CTRL 186
#define PS2_Z_CTRL 187
#define PS2_F1_CTRL 188
#define PS2_F2_CTRL 189
#define PS2_F3_CTRL 190
#define PS2_F4_CTRL 191
#define PS2_F5_CTRL 192
#define PS2_F6_CTRL 193
#define PS2_F7_CTRL 194
#define PS2_F8_CTRL 195
#define PS2_F9_CTRL 206 //196
#define PS2_F10_CTRL 197
#define PS2_F11_CTRL 198
#define PS2_F12_CTRL 199
#define PS2_F1_ALT 229
#define PS2_F2_ALT 230
#define PS2_F3_ALT 231
#define PS2_F4_ALT 232
#define PS2_F5_ALT 233
#define PS2_F6_ALT 234
#define PS2_F7_ALT 235
#define PS2_F8_ALT 236
#define PS2_F9_ALT 237
#define PS2_F10_ALT 238
#define PS2_F11_ALT 239
#define PS2_F12_ALT 240

//#define PS2_INVERTED_EXCLAMATION  161 // ¡
//#define PS2_CENT_SIGN     162 // ¢
//#define PS2_POUND_SIGN      163 // £
#define PS2_CURRENCY_SIGN   164 // ¤
//#define PS2_YEN_SIGN      165 // ¥
//#define PS2_BROKEN_BAR                  166 // ¦
#define PS2_SECTION_SIGN    167 // §
//#define PS2_DIAERESIS     168 // ¨
//#define PS2_COPYRIGHT_SIGN    169 // ©
//#define PS2_FEMININE_ORDINAL    170 // ª
//#define PS2_LEFT_DOUBLE_ANGLE_QUOTE 171 // «
//#define PS2_NOT_SIGN      172 // ¬
//#define PS2_HYPHEN      173
//#define PS2_REGISTERED_SIGN   174 // ®
//#define PS2_MACRON      175 // ¯
#define PS2_DEGREE_SIGN     176 // °
//#define PS2_PLUS_MINUS_SIGN   177 // ±
#define PS2_SUPERSCRIPT_TWO   178 // ²
#define PS2_SUPERSCRIPT_THREE   179 // ³
//#define PS2_ACUTE_ACCENT    180 // ´
#define PS2_MICRO_SIGN      181 // µ
//#define PS2_PILCROW_SIGN    182 // ¶
//#define PS2_MIDDLE_DOT      183 // ·
//#define PS2_CEDILLA     184 // ¸
//#define PS2_SUPERSCRIPT_ONE   185 // ¹
//#define PS2_MASCULINE_ORDINAL   186 // º
//#define PS2_RIGHT_DOUBLE_ANGLE_QUOTE  187 // »
//#define PS2_FRACTION_ONE_QUARTER  188 // ¼
//#define PS2_FRACTION_ONE_HALF   189 // ½
//#define PS2_FRACTION_THREE_QUARTERS 190 // ¾
//#define PS2_INVERTED_QUESTION MARK  191 // ¿
//#define PS2_A_GRAVE     192 // À
//#define PS2_A_ACUTE     193 // Á
//#define PS2_A_CIRCUMFLEX    194 // Â
//#define PS2_A_TILDE     195 // Ã
#define PS2_A_DIAERESIS     196 // Ä
//#define PS2_A_RING_ABOVE    197 // Å
//#define PS2_AE        198 // Æ
//#define PS2_C_CEDILLA     199 // Ç
//#define PS2_E_GRAVE     200 // È
//#define PS2_E_ACUTE     201 // É
//#define PS2_E_CIRCUMFLEX    202 // Ê
//#define PS2_E_DIAERESIS     203 // Ë
//#define PS2_I_GRAVE     204 // Ì
//#define PS2_I_ACUTE     205 // Í
//#define PS2_I_CIRCUMFLEX    206 // Î
//#define PS2_I_DIAERESIS     207 // Ï
//#define PS2_ETH       208 // Ð
//#define PS2_N_TILDE     209 // Ñ
//#define PS2_O_GRAVE     210 // Ò
//#define PS2_O_ACUTE     211 // Ó
//#define PS2_O_CIRCUMFLEX    212 // Ô
//#define PS2_O_TILDE     213 // Õ
#define PS2_O_DIAERESIS     214 // Ö
//#define PS2_MULTIPLICATION    215 // ×
//#define PS2_O_STROKE      216 // Ø
//#define PS2_U_GRAVE     217 // Ù
//#define PS2_U_ACUTE     218 // Ú
//#define PS2_U_CIRCUMFLEX    219 // Û
#define PS2_U_DIAERESIS     220 // Ü
//#define PS2_Y_ACUTE     221 // Ý
//#define PS2_THORN     222 // Þ
#define PS2_SHARP_S     223 // ß
//#define PS2_a_GRAVE     224 // à
//#define PS2_a_ACUTE     225 // á
//#define PS2_a_CIRCUMFLEX    226 // â
//#define PS2_a_TILDE     227 // ã
#define PS2_a_DIAERESIS     228 // ä
//#define PS2_a_RING_ABOVE    229 // å
//#define PS2_ae        230 // æ
//#define PS2_c_CEDILLA     231 // ç
//#define PS2_e_GRAVE     232 // è
//#define PS2_e_ACUTE     233 // é
//#define PS2_e_CIRCUMFLEX    234 // ê
//#define PS2_e_DIAERESIS     235 // ë
//#define PS2_i_GRAVE     236 // ì
//#define PS2_i_ACUTE     237 // í
//#define PS2_i_CIRCUMFLEX    238 // î
//#define PS2_i_DIAERESIS     239 // ï
//#define PS2_eth       240 // ð
//#define PS2_n_TILDE     241 // ñ
//#define PS2_o_GRAVE     242 // ò
//#define PS2_o_ACUTE     243 // ó
//#define PS2_o_CIRCUMFLEX    244 // ô
//#define PS2_o_TILDE     245 // õ
#define PS2_o_DIAERESIS     246 // ö
//#define PS2_DIVISION      247 // ÷
//#define PS2_o_STROKE      248 // ø
//#define PS2_u_GRAVE     249 // ù
//#define PS2_u_ACUTE     250 // ú
//#define PS2_u_CIRCUMFLEX    251 // û
#define PS2_u_DIAERESIS     252 // ü
//#define PS2_y_ACUTE     253 // ý
//#define PS2_thorn     254 // þ
//#define PS2_y_DIAERESIS     255 // ÿ
#endif //defined(OPTION_PS2_KEYBOARD_GERMAN)

#if defined(OPTION_PS2_KEYBOARD_FRENCH)
#define PS2_A_CTRL 162
#define PS2_B_CTRL 200 //163
#define PS2_C_CTRL 164
#define PS2_D_CTRL 165
#define PS2_E_CTRL 166
#define PS2_F_CTRL 201 //167
#define PS2_G_CTRL 202 //168
#define PS2_H_CTRL 169
#define PS2_I_CTRL 170
#define PS2_J_CTRL 171
#define PS2_K_CTRL 172
#define PS2_L_CTRL 173
#define PS2_M_CTRL 174
#define PS2_N_CTRL 175
#define PS2_O_CTRL 203 //176
#define PS2_P_CTRL 177
#define PS2_Q_CTRL 204 //178
#define PS2_R_CTRL 179
#define PS2_S_CTRL 180
#define PS2_T_CTRL 205 //181
#define PS2_U_CTRL 182
#define PS2_V_CTRL 183
#define PS2_W_CTRL 184
#define PS2_X_CTRL 185
#define PS2_Y_CTRL 186
#define PS2_Z_CTRL 187
#define PS2_F1_CTRL 188
#define PS2_F2_CTRL 189
#define PS2_F3_CTRL 190
#define PS2_F4_CTRL 191
#define PS2_F5_CTRL 192
#define PS2_F6_CTRL 193
#define PS2_F7_CTRL 194
#define PS2_F8_CTRL 195
#define PS2_F9_CTRL 196
#define PS2_F10_CTRL 197
#define PS2_F11_CTRL 198
#define PS2_F12_CTRL 199
#define PS2_F1_ALT 233
#define PS2_F2_ALT 234
#define PS2_F3_ALT 235
#define PS2_F4_ALT 236
#define PS2_F5_ALT 237
#define PS2_F6_ALT 238
#define PS2_F7_ALT 239
#define PS2_F8_ALT 240
#define PS2_F9_ALT 241
#define PS2_F10_ALT 242
#define PS2_F11_ALT 243
#define PS2_F12_ALT 244

//#define PS2_INVERTED_EXCLAMATION  161 // ¡
//#define PS2_CENT_SIGN     162 // ¢
#define PS2_POUND_SIGN      163 // £
//#define PS2_CURRENCY_SIGN   164 // ¤
//#define PS2_YEN_SIGN      165 // ¥
//#define PS2_BROKEN_BAR                  166 // ¦
#define PS2_SECTION_SIGN    167 // §
#define PS2_DIAERESIS     168 // ¨
//#define PS2_COPYRIGHT_SIGN    169 // ©
//#define PS2_FEMININE_ORDINAL    170 // ª
//#define PS2_LEFT_DOUBLE_ANGLE_QUOTE 171 // «
//#define PS2_NOT_SIGN      172 // ¬
//#define PS2_HYPHEN      173
//#define PS2_REGISTERED_SIGN   174 // ®
//#define PS2_MACRON      175 // ¯
#define PS2_DEGREE_SIGN     176 // °
//#define PS2_PLUS_MINUS_SIGN   177 // ±
#define PS2_SUPERSCRIPT_TWO   178 // ²
//#define PS2_SUPERSCRIPT_THREE   179 // ³
//#define PS2_ACUTE_ACCENT    180 // ´
#define PS2_MICRO_SIGN      181 // µ
//#define PS2_PILCROW_SIGN    182 // ¶
//#define PS2_MIDDLE_DOT      183 // ·
//#define PS2_CEDILLA     184 // ¸
//#define PS2_SUPERSCRIPT_ONE   185 // ¹
//#define PS2_MASCULINE_ORDINAL   186 // º
//#define PS2_RIGHT_DOUBLE_ANGLE_QUOTE  187 // »
//#define PS2_FRACTION_ONE_QUARTER  188 // ¼
//#define PS2_FRACTION_ONE_HALF   189 // ½
//#define PS2_FRACTION_THREE_QUARTERS 190 // ¾
//#define PS2_INVERTED_QUESTION MARK  191 // ¿
//#define PS2_A_GRAVE     192 // À
//#define PS2_A_ACUTE     193 // Á
//#define PS2_A_CIRCUMFLEX    194 // Â
//#define PS2_A_TILDE     195 // Ã
//#define PS2_A_DIAERESIS     196 // Ä
//#define PS2_A_RING_ABOVE    197 // Å
//#define PS2_AE        198 // Æ
//#define PS2_C_CEDILLA     199 // Ç
//#define PS2_E_GRAVE     200 // È
//#define PS2_E_ACUTE     201 // É
//#define PS2_E_CIRCUMFLEX    202 // Ê
//#define PS2_E_DIAERESIS     203 // Ë
//#define PS2_I_GRAVE     204 // Ì
//#define PS2_I_ACUTE     205 // Í
//#define PS2_I_CIRCUMFLEX    206 // Î
//#define PS2_I_DIAERESIS     207 // Ï
//#define PS2_ETH       208 // Ð
//#define PS2_N_TILDE     209 // Ñ
//#define PS2_O_GRAVE     210 // Ò
//#define PS2_O_ACUTE     211 // Ó
//#define PS2_O_CIRCUMFLEX    212 // Ô
//#define PS2_O_TILDE     213 // Õ
//#define PS2_O_DIAERESIS     214 // Ö
//#define PS2_MULTIPLICATION    215 // ×
//#define PS2_O_STROKE      216 // Ø
//#define PS2_U_GRAVE     217 // Ù
//#define PS2_U_ACUTE     218 // Ú
//#define PS2_U_CIRCUMFLEX    219 // Û
//#define PS2_U_DIAERESIS     220 // Ü
//#define PS2_Y_ACUTE     221 // Ý
//#define PS2_THORN     222 // Þ
//#define PS2_SHARP_S     223 // ß
#define PS2_a_GRAVE     224 // à
//#define PS2_a_ACUTE     225 // á
//#define PS2_a_CIRCUMFLEX    226 // â
//#define PS2_a_TILDE     227 // ã
//#define PS2_a_DIAERESIS     228 // ä
//#define PS2_a_RING_ABOVE    229 // å
//#define PS2_ae        230 // æ
#define PS2_c_CEDILLA     231 // ç
#define PS2_e_GRAVE     232 // è
#define PS2_e_ACUTE     233 // é
//#define PS2_e_CIRCUMFLEX    234 // ê
//#define PS2_e_DIAERESIS     235 // ë
//#define PS2_i_GRAVE     236 // ì
//#define PS2_i_ACUTE     237 // í
//#define PS2_i_CIRCUMFLEX    238 // î
//#define PS2_i_DIAERESIS     239 // ï
//#define PS2_eth       240 // ð
//#define PS2_n_TILDE     241 // ñ
//#define PS2_o_GRAVE     242 // ò
//#define PS2_o_ACUTE     243 // ó
//#define PS2_o_CIRCUMFLEX    244 // ô
//#define PS2_o_TILDE     245 // õ
//#define PS2_o_DIAERESIS     246 // ö
//#define PS2_DIVISION      247 // ÷
//#define PS2_o_STROKE      248 // ø
#define PS2_u_GRAVE     249 // ù
//#define PS2_u_ACUTE     250 // ú
//#define PS2_u_CIRCUMFLEX    251 // û
//#define PS2_u_DIAERESIS     252 // ü
//#define PS2_y_ACUTE     253 // ý
//#define PS2_thorn     254 // þ
//#define PS2_y_DIAERESIS     255 // ÿ
#endif //defined(OPTION_PS2_KEYBOARD_FRENCH)



#define PS2_KEYMAP_SIZE 136

typedef struct {
	uint8_t noshift[PS2_KEYMAP_SIZE];
	uint8_t shift[PS2_KEYMAP_SIZE];
	uint8_t ctrl[PS2_KEYMAP_SIZE];
	uint8_t alt[PS2_KEYMAP_SIZE];
	uint8_t uses_altgr;
	//uint8_t altgr[PS2_KEYMAP_SIZE];       // これは作ってないようだ。
} PS2Keymap_t;


extern const PROGMEM PS2Keymap_t PS2Keymap_JP;
extern const PROGMEM PS2Keymap_t PS2Keymap_US;


/**
 * Purpose: Provides an easy access to PS2 keyboards
 * Author:  Christian Weichel
 */
class PS2Keyboard {
  public:
  	/**
  	 * This constructor does basically nothing. Please call the begin(int,int)
  	 * method before using any other method of this class.
  	 */
    PS2Keyboard();
    
    /**
     * Starts the keyboard "service" by registering the external interrupt.
     * setting the pin modes correctly and driving those needed to high.
     * The propably best place to call this method is in the setup routine.
     * デフォルトは日本語キーボードとする
     */
    static void begin(uint8_t dataPin, uint8_t irq_pin, const PS2Keymap_t &map = PS2Keymap_JP);
    //static void begin(uint8_t dataPin, uint8_t irq_pin, const PS2Keymap_t &map = PS2Keymap_US);
    
    /**
     * Returns true if there is a char to be read, false if not.
     */
    static bool available();
    
    /**
     * Returns the char last read from the keyboard.
     * If there is no char availble, -1 is returned.
     */
    static int read();
	static uint8_t getRcevData();
	static void clrarBuffer();
};

#endif
