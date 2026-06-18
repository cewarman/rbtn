#include "TNlib.h"
#include "network.h"
char Tmp_symC[1][4] = {
	{-30, -124, -125, '\0'}, /** ℃**/
};
char Tmp_symF[1][4] = {
	{-30, -124, -119, '\0'}, /** ℉**/
};
char Number[20][4] = {
	{'0', '\0'},
	{'1', '\0'},
	{'2', '\0'},
	{'3', '\0'},
	{'4', '\0'},
	{'5', '\0'},
	{'6', '\0'},
	{'7', '\0'},
	{'8', '\0'},
	{'9', '\0'},
	{-17, -68, -112, '\0'}, /** 0 **/
	{-17, -68, -111, '\0'}, /** １**/
	{-17, -68, -110, '\0'}, /** ２**/
	{-17, -68, -109, '\0'}, /** ３**/
	{-17, -68, -108, '\0'}, /** ４**/
	{-17, -68, -107, '\0'}, /** ５**/
	{-17, -68, -106, '\0'}, /** ６**/
	{-17, -68, -105, '\0'}, /** ７**/
	{-17, -68, -104, '\0'}, /** ８**/
	{-17, -68, -103, '\0'}, /** ９**/
};
char Non_zero_number[18][4] = {
	{'1', '\0'},
	{'2', '\0'},
	{'3', '\0'},
	{'4', '\0'},
	{'5', '\0'},
	{'6', '\0'},
	{'7', '\0'},
	{'8', '\0'},
	{'9', '\0'},
	{-17, -68, -111, '\0'}, /** １**/
	{-17, -68, -110, '\0'}, /** ２**/
	{-17, -68, -109, '\0'}, /** ３**/
	{-17, -68, -108, '\0'}, /** ４**/
	{-17, -68, -107, '\0'}, /** ５**/
	{-17, -68, -106, '\0'}, /** ６**/
	{-17, -68, -105, '\0'}, /** ７**/
	{-17, -68, -104, '\0'}, /** ８**/
	{-17, -68, -103, '\0'}, /** ９**/
};
char Percentage[3][4] = {
	{-17, -71, -86, '\0'},	/** ﹪**/
	{-17, -68, -123, '\0'}, /** ％**/
	{'%', '\0'}};
char Comma[3][4] = {
	{',', '\0'},			/** ,**/
	{-17, -68, -116, '\0'}, /** ，**/
	{-17, -71, -112, '\0'}, /** ﹐**/
};
char Slash[4][4] = {
	{'/', '\0'},
	{-30, -120, -107, '\0'}, /** ∕**/
	{-30, -107, -79, '\0'},	 /** ╱**/
	{-17, -68, -113, '\0'},	 /** ／**/
};
char Dot[3][4] = {
	{-17, -68, -114, '\0'}, /** ．**/
	{-30, -128, -89, '\0'}, /** ‧**/
	{'.', '\0'},
};
char English[104][4] = {
	{'A', '\0'},			/**0	Ａ**/
	{'B', '\0'},			/**1	Ｂ**/
	{'C', '\0'},			/**2	Ｃ**/
	{'D', '\0'},			/**3	Ｄ**/
	{'E', '\0'},			/**4	Ｅ**/
	{'F', '\0'},			/**5	Ｆ**/
	{'G', '\0'},			/**6	Ｇ**/
	{'H', '\0'},			/**7	Ｈ**/
	{'I', '\0'},			/**8	Ｉ**/
	{'J', '\0'},			/**9	Ｊ**/
	{'K', '\0'},			/**10	Ｋ**/
	{'L', '\0'},			/**11	Ｌ**/
	{'M', '\0'},			/**12	Ｍ**/
	{'N', '\0'},			/**13	Ｎ**/
	{'O', '\0'},			/**14	Ｏ**/
	{'P', '\0'},			/**15	Ｐ**/
	{'Q', '\0'},			/**16	Ｑ**/
	{'R', '\0'},			/**17	Ｒ**/
	{'S', '\0'},			/**18	Ｓ**/
	{'T', '\0'},			/**19	Ｔ**/
	{'U', '\0'},			/**20	Ｕ**/
	{'V', '\0'},			/**21	Ｖ**/
	{'W', '\0'},			/**22	Ｗ**/
	{'X', '\0'},			/**23	Ｘ**/
	{'Y', '\0'},			/**24	Ｙ**/
	{'Z', '\0'},			/**25	Ｚ**/
	{'a', '\0'},			/**26	ａ**/
	{'b', '\0'},			/**27	ｂ**/
	{'c', '\0'},			/**28	ｃ**/
	{'d', '\0'},			/**29	ｄ**/
	{'e', '\0'},			/**30	ｅ**/
	{'f', '\0'},			/**31	ｆ**/
	{'g', '\0'},			/**32	ｇ**/
	{'h', '\0'},			/**33	ｈ**/
	{'i', '\0'},			/**34	ｉ**/
	{'j', '\0'},			/**35	ｊ**/
	{'k', '\0'},			/**36	ｋ**/
	{'l', '\0'},			/**37	ｌ**/
	{'m', '\0'},			/**38	ｍ**/
	{'n', '\0'},			/**39	ｎ**/
	{'o', '\0'},			/**40	ｏ**/
	{'p', '\0'},			/**41	ｐ**/
	{'q', '\0'},			/**42	ｑ**/
	{'r', '\0'},			/**43	ｒ**/
	{'s', '\0'},			/**44	ｓ**/
	{'t', '\0'},			/**45	ｔ**/
	{'u', '\0'},			/**46	ｕ**/
	{'v', '\0'},			/**47	ｖ**/
	{'w', '\0'},			/**48	ｗ**/
	{'x', '\0'},			/**49	ｘ**/
	{'y', '\0'},			/**50	ｙ**/
	{'z', '\0'},			/**51	ｚ**/
	{-17, -68, -95, '\0'},	/**52	Ａ**/
	{-17, -68, -94, '\0'},	/**53	Ｂ**/
	{-17, -68, -93, '\0'},	/**54	Ｃ**/
	{-17, -68, -92, '\0'},	/**55	Ｄ**/
	{-17, -68, -91, '\0'},	/**56	Ｅ**/
	{-17, -68, -90, '\0'},	/**57	Ｆ**/
	{-17, -68, -89, '\0'},	/**58	Ｇ**/
	{-17, -68, -88, '\0'},	/**59	Ｈ**/
	{-17, -68, -87, '\0'},	/**60	Ｉ**/
	{-17, -68, -86, '\0'},	/**61	Ｊ**/
	{-17, -68, -85, '\0'},	/**62	Ｋ**/
	{-17, -68, -84, '\0'},	/**63	Ｌ**/
	{-17, -68, -83, '\0'},	/**64	Ｍ**/
	{-17, -68, -82, '\0'},	/**65	Ｎ**/
	{-17, -68, -81, '\0'},	/**66	Ｏ**/
	{-17, -68, -80, '\0'},	/**67	Ｐ**/
	{-17, -68, -79, '\0'},	/**68	Ｑ**/
	{-17, -68, -78, '\0'},	/**69	Ｒ**/
	{-17, -68, -77, '\0'},	/**70	Ｓ**/
	{-17, -68, -76, '\0'},	/**71	Ｔ**/
	{-17, -68, -75, '\0'},	/**72	Ｕ**/
	{-17, -68, -74, '\0'},	/**73	Ｖ**/
	{-17, -68, -73, '\0'},	/**74	Ｗ**/
	{-17, -68, -72, '\0'},	/**75	Ｘ**/
	{-17, -68, -71, '\0'},	/**76	Ｙ**/
	{-17, -68, -70, '\0'},	/**77	Ｚ**/
	{-17, -67, -127, '\0'}, /**78	ａ**/
	{-17, -67, -126, '\0'}, /**79	ｂ**/
	{-17, -67, -125, '\0'}, /**80	ｃ**/
	{-17, -67, -124, '\0'}, /**81	ｄ**/
	{-17, -67, -123, '\0'}, /**82	ｅ**/
	{-17, -67, -122, '\0'}, /**83	ｆ**/
	{-17, -67, -121, '\0'}, /**84	ｇ**/
	{-17, -67, -120, '\0'}, /**85	ｈ**/
	{-17, -67, -119, '\0'}, /**86	ｉ**/
	{-17, -67, -118, '\0'}, /**87	ｊ**/
	{-17, -67, -117, '\0'}, /**88	ｋ**/
	{-17, -67, -116, '\0'}, /**89	ｌ**/
	{-17, -67, -115, '\0'}, /**90	ｍ**/
	{-17, -67, -114, '\0'}, /**91	ｎ**/
	{-17, -67, -113, '\0'}, /**92	ｏ**/
	{-17, -67, -112, '\0'}, /**93	ｐ**/
	{-17, -67, -111, '\0'}, /**94	ｑ**/
	{-17, -67, -110, '\0'}, /**95	ｒ**/
	{-17, -67, -109, '\0'}, /**96	ｓ**/
	{-17, -67, -108, '\0'}, /**97	ｔ**/
	{-17, -67, -107, '\0'}, /**98	ｕ**/
	{-17, -67, -106, '\0'}, /**99	ｖ**/
	{-17, -67, -105, '\0'}, /**100	ｗ**/
	{-17, -67, -104, '\0'}, /**101	ｘ**/
	{-17, -67, -103, '\0'}, /**102	ｙ**/
	{-17, -67, -102, '\0'}, /**103	ｚ**/
};
char Colon[4][4] = {
	{58, '\0'},				/** :**/
	{-17, -68, -102, '\0'}, /** ：**/
	{-17, -72, -80, '\0'},	/** ︰**/
	{-17, -71, -107, '\0'}	/** ﹕**/
};
char Plus[3][4] = {
	{"+"},
	{-17, -68, -117, '\0'}, /**1  ＋**/
	{-17, -71, -94, '\0'},	/**2  ﹢**/
};
char Dash[6][4] = {
	{"-"},
	{-17, -68, -115, '\0'},	 /**1  －**/
	{-30, -128, -109, '\0'}, /**2  –**/
	{-30, -128, -108, '\0'}, /**3  —**/
	{-30, -108, -128, '\0'}, /**4  ─**/
	{"−"}};
char divide_sign[3] = {-61, -73, '\0'}; /** ÷**/
char multiple_sign[7][4] = {
	{'*', '\0'},			/**  ***/
	{'x', '\0'},			/**  x**/
	{'X', '\0'},			/**  X**/
	{-61, -105, '\0'},		/**  ×**/
	{-30, -107, -77, '\0'}, /**  ╳**/
	{-17, -68, -118, '\0'}, /**  ＊**/
	{-17, -71, -95, '\0'}	/**  ﹡**/
};
char Tilde[2][4] = {
	{"~"},
	{-17, -67, -98, '\0'} /**1  ～**/
};
char UNIT[15][4] = {
	{-27, -115, -127, '\0'}, /*0   十*/
	{-25, -103, -66, '\0'},	 /*1   百*/
	{-27, -115, -125, '\0'}, /*2   千*/
	{-24, -112, -84, '\0'},	 /*3   萬*/
	{-27, -124, -124, '\0'}, /*4   億*/
	{-27, -123, -122, '\0'}, /*5   兆*/
	{-28, -70, -84, '\0'},	 /*6   京*/
	{-27, -98, -109, '\0'},	 /*7   垓*/
	{-25, -89, -83, '\0'},	 /*8   秭*/
	{-25, -87, -80, '\0'},	 /*9   穰*/
	{-26, -70, -99, '\0'},	 /*10  溝*/
	{-26, -66, -105, '\0'},	 /*11  澗*/
	{-26, -83, -93, '\0'},	 /*12  正*/
	{-24, -68, -119, '\0'},	 /*13  載*/
	{-26, -91, -75, '\0'},	 /*14  極*/
};
char CH_number[10][4] = {
	{-23, -101, -74, '\0'},	 /*0  零*/
	{-28, -72, -128, '\0'},	 /*1  一*/
	{-28, -70, -116, '\0'},	 /*2  二*/
	{-28, -72, -119, '\0'},	 /*3  三*/
	{-27, -101, -101, '\0'}, /*4  四*/
	{-28, -70, -108, '\0'},	 /*5  五*/
	{-27, -123, -83, '\0'},	 /*6  六*/
	{-28, -72, -125, '\0'},	 /*7  七*/
	{-27, -123, -85, '\0'},	 /*8  八*/
	{-28, -71, -99, '\0'},	 /*9  九*/
};
char two_for_measure_word[4] = /*兩*/
	{-27, -123, -87, '\0'};
char CH_point[4] = /*點*/
	{-23, -69, -98, '\0'};
char ch_percent[10] = /*百分之*/
	{-25, -103, -66, -27, -120, -122, -28, -71, -117, '\0'};
char ch_per_mill[10] = /*千分之*/
	{-27, -115, -125, -27, -120, -122, -28, -71, -117, '\0'};
char fraction[7] = /*分之*/
	{-27, -120, -122, -28, -71, -117, '\0'};
char proportion[4] = /*比*/
	{-26, -81, -108, '\0'};
char item[4] = /*第*/
	{-25, -84, -84, '\0'};
char ml[7] = /*毫升*/
	{-26, -81, -85, -27, -115, -121, '\0'};
char Tmp_sym_chin_F[7] = /*華氏*/
	{-24, -113, -81, -26, -80, -113, '\0'};
char Tmp_sym_chin_C[7] = /*攝氏*/
	{-26, -108, -99, -26, -80, -113, '\0'};
char Tmp_DO[4] = /*度*/
	{-27, -70, -90, '\0'};
char spaces[3][4] = {
	{" "},
	{"\t"},
	{-29, -128, -128, '\0'}, /*full shape space*/
};
char Ampersand[3][4] = {
	{-17, -68, -122, '\0'}, /*＆*/
	{-17, -71, -96, '\0'},	/*﹠*/
	{38, '\0'}				/*& */
};
char Question[3][4] = {
	{63, '\0'},			   /*?*/
	{-17, -68, -97, '\0'}, /*？*/
	{-17, -71, -106, '\0'} /*﹖*/
};
char Equal_Sign[3][4] = {
	{61, '\0'},			   /** =**/
	{-17, -68, -99, '\0'}, /** ＝**/
	{-17, -71, -90, '\0'}, /** ﹦**/
};
char Under_Line[3][4] = {
	{95, '\0'},			   /** _**/
	{-17, -68, -65, '\0'}, /** ＿**/
	{-53, -115, '\0'},	   /** ˍ**/
};
char Commercial_At[3][4] = {
	{64, '\0'},			   /** @**/
	{-17, -68, -96, '\0'}, /** ＠**/
	{-17, -71, -85, '\0'}, /** ﹫**/
};
char L_Brackets[10][4] = {
	{40, '\0'},				 /** (**/
	{-17, -68, -120, '\0'},	 /** （**/
	{-17, -71, -103, '\0'},	 /** ﹙**/
	{-29, -128, -108, '\0'}, /** 〔**/
	{-29, -128, -120, '\0'}, /** 〈**/
	{-17, -71, -99, '\0'},	 /** ﹝**/
	{-29, -128, -116, '\0'}, /** 「**/
	{-17, -68, -69, '\0'},	 /** ［**/
	{-29, -128, -114, '\0'}, /** 『**/
	{-29, -128, -112, '\0'}, /** 【**/
};
char R_Brackets[10][4] = {
	{41, '\0'},				 /** )**/
	{-17, -68, -119, '\0'},	 /** ）**/
	{-17, -71, -102, '\0'},	 /** ﹚**/
	{-29, -128, -107, '\0'}, /** 〕**/
	{-29, -128, -119, '\0'}, /** 〉**/
	{-17, -71, -98, '\0'},	 /** ﹞**/
	{-29, -128, -115, '\0'}, /** 」**/
	{-17, -68, -67, '\0'},	 /** ］**/
	{-29, -128, -113, '\0'}, /** 』**/
	{-29, -128, -111, '\0'}, /** 】**/
};
char splited_mark[8][7] = {
	{';', '\0'},			 /** ;**/
	{-17, -68, -101, '\0'},	 /** ；**/
	{'!', '\0'},			 /** !**/
	{-17, -68, -127, '\0'},	 /** ！**/
	{-29, -128, -126, '\0'}, /** 。**/
	{'?', '\0'},			 /** ?**/
	{-17, -68, -97, '\0'},	 /** ？**/
	{-17, -71, -106, '\0'},	 /** ﹖**/
};
char Roman_numerals[32][2][5] = {
	{{-30, -123, -96, '\0'}, "I"},	  /**Ⅰ 1   **/
	{{-30, -123, -95, '\0'}, "II"},	  /**Ⅱ 2   **/
	{{-30, -123, -94, '\0'}, "III"},  /**Ⅲ 3   **/
	{{-30, -123, -93, '\0'}, "IV"},	  /**Ⅳ 4   **/
	{{-30, -123, -92, '\0'}, "V"},	  /**Ⅴ 5   **/
	{{-30, -123, -91, '\0'}, "VI"},	  /**Ⅵ 6   **/
	{{-30, -123, -90, '\0'}, "VII"},  /**Ⅶ 7   **/
	{{-30, -123, -89, '\0'}, "VIII"}, /**Ⅷ 8   **/
	{{-30, -123, -88, '\0'}, "IX"},	  /**Ⅸ 9   **/
	{{-30, -123, -87, '\0'}, "X"},	  /**Ⅹ 10  **/
	{{-30, -123, -86, '\0'}, "XI"},	  /**Ⅺ 11  **/
	{{-30, -123, -85, '\0'}, "XII"},  /**Ⅻ 12  **/
	{{-30, -123, -84, '\0'}, "L"},	  /**Ⅼ 50  **/
	{{-30, -123, -83, '\0'}, "C"},	  /**Ⅽ 100 **/
	{{-30, -123, -82, '\0'}, "D"},	  /**Ⅾ 500 **/
	{{-30, -123, -81, '\0'}, "M"},	  /**Ⅿ 1000**/
	{{-30, -123, -80, '\0'}, "i"},	  /**ⅰ 1   **/
	{{-30, -123, -79, '\0'}, "ii"},	  /**ⅱ 2   **/
	{{-30, -123, -78, '\0'}, "iii"},  /**ⅲ 3   **/
	{{-30, -123, -77, '\0'}, "iv"},	  /**ⅳ 4   **/
	{{-30, -123, -76, '\0'}, "v"},	  /**ⅴ 5   **/
	{{-30, -123, -75, '\0'}, "vi"},	  /**ⅵ 6   **/
	{{-30, -123, -74, '\0'}, "vii"},  /**ⅶ 7   **/
	{{-30, -123, -73, '\0'}, "viii"}, /**ⅷ 8   **/
	{{-30, -123, -72, '\0'}, "ix"},	  /**ⅸ 9   **/
	{{-30, -123, -71, '\0'}, "x"},	  /**ⅹ 10  **/
	{{-30, -123, -70, '\0'}, "xi"},	  /**ⅺ 11  **/
	{{-30, -123, -69, '\0'}, "xii"},  /**ⅻ 12  **/
	{{-30, -123, -68, '\0'}, "l"},	  /**ⅼ 50  **/
	{{-30, -123, -67, '\0'}, "c"},	  /**ⅽ 100 **/
	{{-30, -123, -66, '\0'}, "d"},	  /**ⅾ 500 **/
	{{-30, -123, -65, '\0'}, "m"}	  /**ⅿ 1000**/
};
char currency_symbols[22][7] = {
	{36, '\0'},							   /** $**/
	{-17, -68, -124, '\0'},				   /** ＄**/
	{-17, -65, -91, '\0'},				   /** ￥**/
	{-62, -91, '\0'},					   /** ¥**/
	{-17, -65, -95, '\0'},				   /** ￡**/
	{-62, -93, '\0'},					   /** £**/
	{-30, -126, -84, '\0'},				   /** €**/
	{-17, -65, -96, '\0'},				   /** ￠**/
	{-30, -126, -87, '\0'},				   /** ₩**/
	{-30, -126, -85, '\0'},				   /** ₫**/
	{-32, -72, -65, '\0'},				   /** ฿**/
	{-30, -126, -79, '\0'},				   /** ₱**/
	{-31, -97, -101, '\0'},				   /** ៛**/
	{-30, -126, -71, '\0'},				   /** ₹**/
	{-30, -126, -88, '\0'},				   /** ₨**/
	{-30, -126, -90, '\0'},				   /** ₦**/
	{-30, -126, -75, '\0'},				   /** ₵**/
	{-30, -126, -95, '\0'},				   /** ₡**/
	{-31, -125, -102, '\0'},			   /** ლ**/
	{-34, -125, '\0'},					   /** ރ**/
	{-32, -82, -80, -32, -81, -126, '\0'}, /** ரூ**/
	{-32, -89, -77, '\0'},				   /** ৳ூ**/
};
char country_abbr[8][2][16] = {
	{"NT", {-26, -106, -80, -27, -113, -80, -27, -71, -93, '\0'}},				   /** 新台幣 **/
	{"HK", {-26, -72, -81, -27, -71, -93, '\0'}},								   /** 港幣 **/
	{"US", {-25, -66, -114, -27, -123, -125, '\0'}},							   /** 美元 **/
	{"CAN", {-27, -118, -96, -26, -117, -65, -27, -92, -89, -27, -71, -93, '\0'}}, /** 加拿大幣 **/
	{"A", {-26, -66, -77, -27, -123, -125, '\0'}},								   /** 奧元 **/
	{"NZ", {-26, -106, -80, -24, -91, -65, -24, -104, -83, -27, -71, -93, '\0'}},  /** 新西蘭幣 **/
	{"RMB", {-28, -70, -70, -26, -80, -111, -27, -71, -93, '\0'}},				   /** 人民幣 **/
	{"S", {-26, -106, -80, -27, -118, -96, -27, -99, -95, -27, -71, -93, '\0'}},   /** 新加坡幣 **/
};
char currsym2spokenform[18][3][16] = {
	{{-17, -65, -95, '\0'}, "pound", {-23, -114, -118, '\0'}},								   /**￡   Pound   鎊**/
	{{-62, -93, '\0'}, "pound", {-23, -114, -118, '\0'}},									   /**£   Pound   鎊**/
	{{-30, -126, -84, '\0'}, "euro", {-26, -83, -112, -27, -123, -125, '\0'}},				   /**€   Euro    歐元**/
	{{-17, -65, -96, '\0'}, "cent", {-27, -120, -122, '\0'}},								   /**￠   cent    分**/
	{{-30, -126, -87, '\0'}, "won", {-23, -97, -109, -27, -123, -125, '\0'}},				   /**₩    Won   韓元**/
	{{-30, -126, -85, '\0'}, "dong", {-24, -74, -118, -27, -115, -105, -25, -101, -66, '\0'}}, /**₫   Dong    越南盾**/
	{{-32, -72, -65, '\0'}, "baht", {-26, -77, -80, -23, -118, -106, '\0'}},				   /**฿   baht    泰銖**/
	{{-30, -126, -79, '\0'}, "peso", {-26, -118, -85, -25, -76, -94, '\0'}},				   /**₱   peso    披索**/
	{{-31, -97, -101, '\0'}, "riel", {-25, -111, -98, -25, -120, -66, '\0'}},				   /**៛   riel    瑞爾**/
	{{-30, -126, -71, '\0'}, "rupee", {-25, -101, -89, -26, -81, -108, '\0'}},				   /**₹   rupee   盧比**/
	{{-30, -126, -88, '\0'}, "rupiah", {-25, -101, -89, -26, -81, -108, '\0'}},				   /**₨   rupiah  盧比**/
	{{-30, -126, -90, '\0'}, "naira", {-27, -91, -120, -26, -117, -119, '\0'}},				   /** ₦	naira	奈拉**/
	{{-30, -126, -75, '\0'}, "cedi", {-27, -95, -98, -27, -100, -80, '\0'}},				   /** ₵	cedi	塞地**/
	{{-30, -126, -95, '\0'}, "colon", {-27, -123, -117, -26, -100, -105, '\0'}},			   /** ₡	colón	克朗**/
	{{-31, -125, -102, '\0'}, "lari", {-26, -117, -119, -23, -121, -116, '\0'}},			   /** ლ	lari	拉里**/
	{{-34, -125, '\0'}, "rufiyaa", {-25, -101, -89, -24, -113, -78, -28, -70, -98, '\0'}},	   /** ރ	rufiyaa	盧菲亞**/
	{{-32, -82, -80, -32, -81, -126, '\0'}, "rupee", {-25, -101, -89, -26, -81, -108, '\0'}},  /** ரூ	rupee	盧比**/
	{{-32, -89, -77, '\0'}, "taka", {-27, -95, -108, -27, -115, -95, '\0'}}					   /** ৳ூ	taka	塔卡**/
};
char mandarin_money[4] = {-27, -123, -125, '\0'}; /** 元 **/
char number_sign[3][4] = {
	{'#', '\0'},
	{-17, -68, -125, '\0'}, /** ＃ **/
	{-17, -71, -97, '\0'}	/** ﹟ **/
};
char ch_dao[4] = {-27, -120, -80, '\0'} /** 到**/;
char ch_zh4[4] = {-24, -121, -77, '\0'} /** 至**/;
char ch_paa[4] = {-27, -107, -86, '\0'} /** 啪**/;
char ch_feng[4] = {-27, -120, -122, '\0'}; /** 分**/
char ch_miao[4] = {-25, -89, -110, '\0'} /** 秒**/;
char ch_plus[4] = {-27, -118, -96, '\0'};						/** 加**/
char ch_minus[4] = {-26, -72, -101, '\0'};						/** 減**/
char ch_negative[4] = {-24, -78, -96, '\0'};					/** 負**/
char ch_floor[4] = {-26, -88, -109, '\0'};						/** 樓**/
char ch_divide_by[7] = {-23, -103, -92, -28, -69, -91, '\0'};	/** 除以**/
char ch_multiply_by[7] = {-28, -71, -104, -28, -69, -91, '\0'}; /**  乘以**/
char ch_euqal[7] = {-25, -83, -119, -26, -106, -68, '\0'};		/**  等於**/
char ch_ratio[4] = {-26, -81, -108, '\0'};						/** 比**/
char ch_hour[7] = {-27, -80, -113, -26, -103, -126, '\0'};
char ch_question[7] = {-27, -107, -113, -24, -103, -97, '\0'};
char ch_Equal_Sign[7] = {-25, -83, -119, -24, -103, -97, '\0'};
char ch_Under_Line[7] = {-27, -70, -107, -25, -73, -102, '\0'};
char ch_Colon[7] = {-27, -122, -110, -24, -103, -97, '\0'};
char crtl_char[6][6] = {{_NAN_}, {_NAE_}, {_NAM_}, {_IAN_}, {_IAE_}, {_IAM_}};
char one_yiao[4] = {-28, -71, -120, '\0'};						/** 么**/
char Mandarin_time[4] = {-26, -103, -126, '\0'};				/** 時**/
char Mandarin_year[4] = {-27, -71, -76, '\0'};					/**  年**/
char Mandarin_month[4] = {-26, -100, -120, '\0'};				/**  月**/
char Mandarin_day[4] = {-26, -105, -91, '\0'};					/**  日**/
char Mandarin_number[4] = {-24, -103, -97, '\0'};				/**  號**/
char Mandarin_grade[7] = {-27, -71, -76, -25, -76, -102, '\0'}; /**  年級**/
char Mandarin_decimal_point[4] = {-29, -125, -69, '\0'};		/** ・**/
char Mandarin_discount[4] = {-26, -118, -104, '\0'};			/** 折**/
char Dose[4] = {-27, -118, -111, '\0'};							/** 劑**/
char English_number[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char English_teens[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char English_tys[8][9] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char English_hundred[8] = {"hundred"};
char English_unit[10][12] = {"thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion"};
char week_worship[2][7] = {
	{-26, -104, -97, -26, -100, -97, '\0'}, /** 星期**/
	{-25, -90, -82, -26, -117, -100, '\0'}, /** 禮拜**/
};
char mathematical_symbols[6][3][32] = {
	{{-30, -119, -96, '\0'}, {-28, -72, -115, -25, -83, -119, -26, -106, -68, '\0'}, " not-euqal "},							   /** ≠	不等於		not_euqal**/
	{{-30, -119, -92, '\0'}, {-27, -80, -113, -26, -106, -68, -25, -83, -119, -26, -106, -68, '\0'}, "less-than-or-equal-to "},	   /** ≤	小於等於	less than or equal to**/
	{{-30, -119, -91, '\0'}, {-27, -92, -89, -26, -106, -68, -25, -83, -119, -26, -106, -68, '\0'}, " greater-than-or-equal-to "}, /** ≥	大於等於	greater than or equal to**/
	{{-61, -73, '\0'}, {-23, -103, -92, -28, -69, -91, '\0'}, " divided-by "},													   /** ÷	除以		divided by**/
	{{-30, -120, -102, '\0'}, {-26, -96, -71, -24, -103, -97, '\0'}, "square root "},											   /** √	根號		square root**/
	{{-30, -120, -98, '\0'}, {-25, -124, -95, -25, -86, -82, '\0'}, "infinity "},												   /** ∞	無窮		infinity**/
};
char mathematical_symbols_english_only[2][2][32] = {
	{{-30, -106, -77, '\0'}, "delta "}, /**△	delta**/
	{{-49, -128, '\0'}, "pi "},			/**π	pi**/
};
char unit_table[1][2][32] = {
	{{"m2"}, {-27, -71, -77, -25, -79, -77, '\0'}}, /** m2	平米**/
};
FN_MAP fn_map[] = {
    {"NTISFW", NTISFW},
    {"DPTSFW", DPTSFW},
    {"MMTDSF", MMTDSF},
    {"NWMSFW", NWMSFW},
	{"DMYTSF", DMYTSF},
	{"DTDYMD", DTDYMD},
	{"FRACSFW", FRACSFW},
	{"PTSFW", PTSFW},
	{"N2SSTF", N2SSTF},
	{"N2SWND", N2SWND},
	{"N2IWND", N2IWND},
	{"TADSRB", TADSRB},
	{"URLNOR", URLNOR},
	{"EMAILN", EMAILN},
	{"NESWND", NESWND},
	{"MDTOMD", MDTOMD},
	{"DMTODM", DMTODM},
	{"MDWNDI", MDWNDI},
	{"HMTOHM", HMTOHM},
	{"HMTSFW", HMTSFW},
	{"COMPRO", COMPRO},
	{"NTONPG", NTONPG},
	{"SFWFSC", SFWFSC},
	{"RSFWTF", RSFWTF},
	{"FSFWTF", FSFWTF},
	{"HICTU8", HICTU8},
	{"TTFHSF", TTFHSF},
	{"YMTYMT", YMTYMT},
	{"CH_N2SWND", CH_N2SWND},
	{"MS2SFW", MS2SFW},
	{"DCSOIN", DCSOIN},
	{"CONAFF", CONAFF},
	{"NSFWSP", NSFWSP},
	{"PRNTPG", PRNTPG},
	{"RACTEA", RACTEA},
	{"DSPFWW", DSPFWW},
	{"CMNTSW", CMNTSW},
	{"CMFSFW", CMFSFW},
	{"CASSWA", CASSWA},
	{"ECCWPS", ECCWPS},
	{"ABOYTY", ABOYTY},
	{"GFGCAS", GFGCAS},
	{"RUOEAO", RUOEAO},
	{"TPEFRU", TPEFRU},
	{"RUTMSF", RUTMSF},
	{"N2SWND_FT", N2SWND_FT},
	{"TN77SE", TN77SE},
	{"FFDFCD", FFDFCD},
	{"N2SSTF_LD", N2SSTF_LD},
	{"EDNMNT", EDNMNT},
	{"NINB4I", NINB4I},
	{"YMTSFW", YMTSFW},
	{"MSTSFW", MSTSFW},
	{"UAPPUN", UAPPUN},
	{"NNLIRW", NNLIRW},
	{"NILNRW", NILNRW},
	{"PN2SFW", PN2SFW},
	{"MSDWDW", MSDWDW},
	{"MDD2YM", MDD2YM},
	{"NEIWND", NEIWND},
	{"EANAPN", EANAPN},
	{"VMPNDN", VMPNDN},
	{"THCMCS", THCMCS},
	{"UAPPMU", UAPPMU},
	{"RSFSTF", RSFSTF},
	{"SEMINS", SEMINS},
	{"MYSHUT", MYSHUT},
	{"DPWAID", DPWAID},
	{"YMOMDT", YMOMDT},
	{"N2SCAC", N2SCAC},
	{"MASAFW", MASAFW},
	{"EAWWON", EAWWON},
	{"CFTSFW", CFTSFW},
	{"RWAPAS", RWAPAS},
	{"RWPOST", RWPOST},
	{"CRTSFW", CRTSFW},
	{"LATEXT", LATEXT},
	{"HSAESF", HSAESF},
	{"DAFROL", DAFROL},
	{"MDHMTO", MDHMTO},
	{"NFNLT4", NFNLT4},
	{"THMSSF", THMSSF},
	{"NFSNFS", NFSNFS},
	{"NFNLT3", NFNLT3},
	{"NUDLOP", NUDLOP},
	{"CNWAAN", CNWAAN},
	
};
int isTmp_symC(char *word)
{
	int i;
	for (i = 0; i < 1; i++)
	{
		if (strcmp(word, Tmp_symC[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isTmp_symF(char *word)
{
	int i;
	for (i = 0; i < 1; i++)
	{
		if (strcmp(word, Tmp_symF[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isComma(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Comma[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isSlash(char *word)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(word, Slash[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isNumber_sign(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, number_sign[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isNumber(char *word)
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (strcmp(word, Number[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int AllisNumber(char *line)
{
	int i, idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			return 0;
		}
	}

	return 1;
}
int isDot(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Dot[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isNon_zero_number(char *word)
{
	int i;
	for (i = 0; i < 18; i++)
	{
		if (strcmp(word, Non_zero_number[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isEnglish(char *word)
{
	/*int i;
	for (i = 0; i < 104; i++)
	{
		if (strcmp(word, English[i]) == 0)
		{
			return 1;
		}
	}*/
	if (strlen(word) == 1)
	{
		if ((word[0] >= 65 && word[0] <= 90) || (word[0] >= 97 && word[0] <= 122))
		{
			return 1;
		}
	}
	else if (strlen(word) == 3)
	{
		if (word[0] == -17)
		{
			if (word[1] == -67)
			{
				if (word[2] >= -127 && word[2] <= -102)
				{
					return 1;
				}
			}
			else if (word[1] == -68)
			{
				if (word[2] >= -95 && word[2] <= -70)
				{
					return 1;
				}
			}
		}
	}

	return 0;
}
int iscurrency_symbol(char *word)
{
	int i;
	for (i = 0; i < 22; i++)
	{
		if (strcmp(word, currency_symbols[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int ismultiple_sign(char *word)
{
	int i;
	for (i = 0; i < 7; i++)
	{
		if (strcmp(word, multiple_sign[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int issplited_mark(char *word)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (strcmp(word, splited_mark[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isR_Brackets(char *word)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(word, R_Brackets[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isL_Brackets(char *word)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(word, L_Brackets[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isCommercial_At(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Commercial_At[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isunder_line(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Under_Line[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isequal_sign(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Equal_Sign[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isquestion(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Question[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isampersand(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Ampersand[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isPercentage(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Percentage[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isColon(char *word)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(word, Colon[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isPlus(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, Plus[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isDash(char *word)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (strcmp(word, Dash[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isTilde(char *word)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		if (strcmp(word, Tilde[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int isapostrophe(char *word)
{
	char full_apostrophe[4] = {-30, -128, -103, '\0'};

	if (strcmp(word, "\'") == 0 || strcmp(word, full_apostrophe) == 0)
	{
		return 1;
	}

	return 0;
}

int parser_line(char *line, char *istate, char *ostate, char *itemp,
				char *otemp, char *wtemp)
{
	int i, index;

	for (i = 0, index = 0;
		 line[index] != '\t' && line[index] != ' ' && line[index] != '\n';
		 i++, index++)
	{
		istate[i] = line[index];
	}
	istate[i] = '\0';
	if (line[index] == '\n')
	{
		strcpy(wtemp, "0.0");
		return 1;
	}
	for (i = 0, index++;
		 line[index] != '\t' && line[index] != ' ' && line[index] != '\n';
		 i++, index++)
	{
		ostate[i] = line[index];
	}
	ostate[i] = '\0';
	if (line[index] == '\n')
	{
		strcpy(wtemp, ostate);
		return 1;
	}
	for (i = 0, index++; line[index] != '\t' && line[index] != ' ';
		 i++, index++)
	{
		itemp[i] = line[index];
	}
	itemp[i] = '\0';
	for (i = 0, index++;
		 line[index] != '\n' && line[index] != '\t' && line[index] != ' ';
		 i++, index++)
	{
		otemp[i] = line[index];
	}
	otemp[i] = '\0';
	if (line[index] == '\t' || line[index] == ' ')
	{
		for (i = 0, index++; line[index] != '\n'; i++, index++)
		{
			wtemp[i] = line[index];
		}
		// wtemp[0]='-';
		wtemp[i] = '\0';
	}
	else
	{
		strcpy(wtemp, "0.0");
	}
	return 0;
}
int read_a_utf8_word(char *line, char *word, int *index)
{
	unsigned char trick = 64;	// 0x01000000
	unsigned char trick1 = 128; // 0x10000000
	int i = 1;

	word[0] = line[(*index)++];
	if (word[0] == '\0')
	{
		word[i] = '\0';
		(*index)--;
		return 1;
	}
	while (word[0] & trick && word[0] & trick1)
	{
		word[i++] = line[(*index)++];
		trick = trick >> 1;
	}
	word[i] = '\0';

	return 0;
}
int utf8_word_length(char *word)
{
	int length = 0;
	unsigned int index = 0, end_idx = strlen(word);
	for (; index < end_idx;)
	{
		if (word[index] > 0)
			index += 1;
		else if (word[index] > -65 && word[index] < -32)
			index += 2;
		else if (word[index] > -33 && word[index] < -16)
			index += 3;
		else if (word[index] > -17 && word[index] < -8)
			index += 4;
		else if (word[index] > -9 && word[index] < -4)
			index += 5;
		else if (word[index] > -5 && word[index] < -2)
			index += 6;
		else
		{
			printf("format error, %s is not utf8.\n", word);
			exit(1);
		}

		length++;
	}
	return length;
}
int isCJK_words(char *word)
{
	// class										unicode		UTF-8				UTF-8_deciaml			size
	// CJK_Kangxi_Radicals						2F00-2FDF	e2bc80-e2bf9f		14859392-14860191		800
	// CJK_Radicals_Supplement					2E80-2EFF	e2ba80-e2bbbf		14858880-14859199		320
	// CJK_Unified_Ideographs_Extension_A		3400-4DBF	e39080-e4b6bf		14913664-14988991		75328
	// CJK-Unified_Ideographs					4E00-9FFF	e4b880-e9bfbf		14989440-15318975		329536
	// CJK-Compatibility_Ideographs				F900-FAFF	efa480-efabbf		15705216-15707071		1856
	// CJK_Unified_Ideographs_Extension_B		20000-2A6DF	f0a08080-f0aa9b9f	4037050496-4037712799	662304
	// CJK_Unified_Ideographs_Extension_C		2A700-2B73F	f0aa9c80-f0ab9cbf	4037713024-4037778623	65600
	// CJK_Unified_Ideographs_Extension_D		2B740-2B81F	f0ab9d80-f0aba09f	4037778816-4037779615	800
	// CJK_Unified_Ideographs_Extension_E		2B820-2CEAF	f0aba0a0-f0acbaaf	4037779616-4037851823	72208
	// CJK_Unified_Ideographs_Extension_F		2CEB0-2EBEF	f0acbab0-f0aeafaf	4037851824-4037980079	128256
	// CJK-Compatibility_Ideographs_Supplement	2F800-2FA1F	f0afa080-f0afa89f	4038041728-4038043807	2080
	// CJK_Unified_Ideographs_Extension_G		30000-3134A	f0b08080-f0b18d8a	4038099072-4038167946	68875

	unsigned long long int utf8_value = 0;
	if (strlen(word) == 3)
	{
		utf8_value = utf8word2decimal(word);
		if ((utf8_value >= 14859392 && utf8_value <= 14860191) ||
			(utf8_value >= 14858880 && utf8_value <= 14859199) ||
			(utf8_value >= 14913664 && utf8_value <= 14988991) ||
			(utf8_value >= 14989440 && utf8_value <= 15318975) ||
			(utf8_value >= 15705216 && utf8_value <= 15707071))
		{
			return 1;
		}
	}
	else if (strlen(word) == 4)
	{
		utf8_value = utf8word2decimal(word);
		if ((utf8_value >= 4037050496 && utf8_value <= 4037712799) ||
			(utf8_value >= 4037713024 && utf8_value <= 4037778623) ||
			(utf8_value >= 4037778816 && utf8_value <= 4037779615) ||
			(utf8_value >= 4037779616 && utf8_value <= 4037851823) ||
			(utf8_value >= 4037851824 && utf8_value <= 4037980079) ||
			(utf8_value >= 4038041728 && utf8_value <= 4038043807) ||
			(utf8_value >= 4038099072 && utf8_value <= 4038167946))
		{
			return 1;
		}
	}
	// printf("%s %lu\n",word, utf8_value);

	return 0;
}
int isAscii(char *sentance)
{
	int index = 0;
	char word[7];
	read_a_utf8_word(sentance, word, &index);
	if (index == strlen(sentance))
	{
		return 1; // 為字元
	}
	else
	{
		return 0; // 為字串
	}
}
unsigned long long int utf8word2decimal(char *word)
{
	unsigned long long int ret = 0;
	int num_byte = strlen(word);
	int i;

	for (i = 0; i < num_byte; i++)
	{
		ret = ret << 8;
		ret += ((unsigned long long int)word[i]) & 255;
	}
	return ret;
}
int read_a_line(char **line, int *capacity_of_line, FILE *fin)
{
	char temp[1024];
	int cnt, times, ENDOFLINE = 0, FILEEND = 0;

	for (*line[0] = '\0', times = 1; ENDOFLINE == 0; times++)
	{
		for (cnt = 0; 1; cnt++)
		{
			temp[cnt] = fgetc(fin);
			if (temp[cnt] == '\n' || temp[cnt] == EOF || cnt == 1022)
			{
				if (temp[cnt] == '\n' || temp[cnt] == EOF)
				{
					ENDOFLINE = 1;
					if (temp[cnt] == EOF)
					{
						FILEEND = 1;
					}
					temp[cnt] = '\0';
				}
				break;
			}
		}
		if (*capacity_of_line < times * 1024)
		{
			*line = (char *)realloc(*line, times * 1024 * sizeof(char));
			*capacity_of_line = times * 1024;
			// printf("%d %d %d\n", times, (times - 1) * 1024 - times + 1,
			// *capacity_of_line);
			(*line)[(times - 1) * 1024 - times + 1] = '\0';
		}
		if (cnt == 1022)
		{
			temp[cnt + 1] = '\0';
		}
		strcat(*line, temp);
	}
	// printf("%s\n", *line);

	return FILEEND;
}
int Retreat_a_utf8_word(char *line, int *index)
{
	if ((*index) == 0)
	{
		return 0;
	}

	if (line[(*index) - 1] > 0)
	{
		(*index) -= 1;
		return 1;
	}
	else if (line[(*index) - 2] >= -64 && line[(*index) - 2] <= -33)
	{
		(*index) -= 2;
		return 2;
	}
	else if (line[(*index) - 3] >= -32 && line[(*index) - 3] <= -17)
	{
		(*index) -= 3;
		return 3;
	}
	else if (line[(*index) - 4] >= -16 && line[(*index) - 4] <= -9)
	{
		(*index) -= 4;
		return 4;
	}
	else if (line[(*index) - 5] >= -8 && line[(*index) - 5] <= -5)
	{
		(*index) -= 5;
		return 5;
	}
	else if (line[(*index) - 6] >= -4 && line[(*index) - 6] <= -3)
	{
		(*index) -= 6;
		return 6;
	}
	else
	{
		printf("line=\"%s\", index=%d\n", line, *index);
		printf("%d %d %d %d %d %d %d\n", line[(*index) - 6], line[(*index) - 5], line[(*index) - 4], line[(*index) - 3], line[(*index) - 2], line[(*index) - 1], line[(*index)]);
		fprintf(stdout, "Retreat error : not utf-8 format.\n");
		fflush(stdout);
		exit(1);
	}
	return 1;
}
void destroy_fst(FST *fst)
{
	int i;

	for (i = 0; i < fst->num_state; i++)
	{
		free(fst->aiit.forward_arcs[i]);
	}
	free(fst->aiit.forward_arcs);
	free(fst->aiit.state_regular_input_length);
	free(fst->aiit.eps_input_arcs);
	free(fst->aiit.non_regular_input_arcs);
	free(fst->aiit.possible_forward);
	free(fst->aiit.regular_inputs);
	free(fst->arc);
}
void destroy_text(TEXT *text)
{
	int i;

	for (i = 0; i < text->num_of_sentence; i++)
	{
		free(text->sentence[i]);
	}
	free(text->sentence);
}
void ini_nsw(NSW_TOKEN *nsw)
{
	int i;

	nsw->capacity = NUM_EXTERN;
	nsw->size = 0;
	nsw->rule = (char **)malloc(nsw->capacity * sizeof(char *));
	nsw->end_idx = (int *)malloc(nsw->capacity * sizeof(int));
	nsw->start_idx = (int *)malloc(nsw->capacity * sizeof(int));
	nsw->language = (int *)malloc(nsw->capacity * sizeof(int));
	nsw->token = (char **)malloc(nsw->capacity * sizeof(char *));
	nsw->SFW = (char **)malloc(nsw->capacity * sizeof(char *));
	for (i = 0; i < nsw->capacity; i++)
	{
		nsw->rule[i] = (char *)malloc(sizeof(char));
		nsw->token[i] = (char *)malloc(sizeof(char));
		nsw->SFW[i] = (char *)malloc(sizeof(char));
	}
}
void destroy_nsw(NSW_TOKEN *nsw)
{
	int i;

	for (i = 0; i < nsw->capacity; i++)
	{
		free(nsw->rule[i]);
		free(nsw->token[i]);
		free(nsw->SFW[i]);
	}
	free(nsw->rule);
	free(nsw->end_idx);
	free(nsw->start_idx);
	free(nsw->language);
	free(nsw->token);
	free(nsw->SFW);
}
void paser_a_sentence(FST *fst, VITERBIINFO *vinfo, char *line, NSW_TOKEN *nsw)
{
	int i, idx;
	int len_of_line = utf8_word_length(line);
	char word[7];

	nsw->size = 0;
	for (i = idx = 0; read_a_utf8_word(line, word, &idx) == 0; i++)
	{
		// printf("%s idx=%d\n", word, idx);
		// fflush(stdout);
		forward_all_table_binsearch(fst, vinfo, line, &idx, word, nsw);
	}
	// printf("%s\nnsw_num:%d\n", line, nsw->size);
	// for (i = 0; i < nsw->size; i++)
	//{
	//	printf("%d %d %s %s %d\n", nsw->start_idx[i], nsw->end_idx[i], nsw->token[i], nsw->rule[i], nsw->language[i]);
	// }
	// printf("done\n");
	// fflush(stdout);
}
void forward_all_table_binsearch(FST *fst, VITERBIINFO *vinfo, char *sentence, int *idx, char *word, NSW_TOKEN *nsw)
{
	int i, j, k, flag, num_sur_pre_state, num_sur_cur_state, temp_arc_idx, temp_state, temp_input_idx;
	int pre_index, cur_index, pseudo_cur_index, pseudo_pre_index, ret, depth;
	OSYM *temp, **temp_sur_state_osym, *of = NULL;
	int start_idx, comp_idx = *idx, replace_flag = 0, Retreat_flag = 0, temp_step, temp_idx;
	char temp_word[7];
	int *temp_sur_state_num;
	int compare_end_index, compare_length;

	vinfo->sur_pre_state[0] = 0;
	for (i = 0; i < vinfo->len; i++)
	{
		vinfo->pre_state[i] = NULL;
		vinfo->cur_state[i] = NULL;
	}
	fill_osym(&of, &vinfo->pre_state[0], 1, 0, "<eps>", "<eps>", 0);
	num_sur_pre_state = 1;

	Retreat_a_utf8_word(sentence, idx);
	start_idx = *idx;
	Retreat_a_utf8_word(sentence, &comp_idx);
	for (flag = 0, depth = 1;; depth++)
	{
		// ret = read_a_utf8_word(sentence, word, idx);
		// printf("%d %d %d %d %s\n", *idx, start_idx, comp_idx, depth, &sentence[comp_idx]);
		// fflush(stdout);

		for (i = num_sur_cur_state = 0; i < num_sur_pre_state; i++)
		{
			pre_index = vinfo->sur_pre_state[i];
			// printf("%d eps_input_num=%d\n", pre_index, fst->aiit.eps_input_num[pre_index]);
			for (j = 0; j < fst->aiit.eps_input_num[pre_index]; j++)
			{
				temp_arc_idx = fst->aiit.eps_input_arcs[pre_index][j];
				// printf("%d %d %s %s\n", fst->arc[temp_arc_idx].istate, fst->arc[temp_arc_idx].ostate, fst->arc[temp_arc_idx].itemp, fst->arc[temp_arc_idx].otemp);
				temp_state = fst->arc[temp_arc_idx].ostate;
				ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->pre_state[temp_state], vinfo->pre_state[pre_index]->depth, temp_state, "<eps>", fst->arc[temp_arc_idx].otemp, vinfo->pre_state[pre_index]->forward_step);
				// printf("ret = %d\n", ret);
				if (ret == 0)
				{
					vinfo->sur_pre_state[num_sur_pre_state++] = temp_state;
				}
			}
			// printf("%d non_regular_input_arc_num=%d\n", pre_index, fst->aiit.non_regular_input_arc_num[pre_index]);
			for (j = 0; j < fst->aiit.non_regular_input_arc_num[pre_index]; j++)
			{
				temp_arc_idx = fst->aiit.non_regular_input_arcs[pre_index][j];
				cur_index = fst->arc[temp_arc_idx].ostate;
				if (strcmp(fst->arc[temp_arc_idx].itemp, "<sentence_start>") == 0)
				{
					if ((*idx) == 0)
					{
						cur_index = fst->arc[temp_arc_idx].ostate;
						ret = fill_osym(&vinfo->pre_state[0], &vinfo->cur_state[cur_index], 1, cur_index, "", fst->arc[temp_arc_idx].otemp, 0);
						if (ret == 0)
						{
							vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
						}
					}
				}
				else if (strcmp("<filler>", fst->arc[temp_arc_idx].itemp) == 0)
				{
					temp_idx = start_idx + vinfo->pre_state[pre_index]->forward_step;
					read_a_utf8_word(sentence, temp_word, &temp_idx);
					temp_step = vinfo->pre_state[pre_index]->forward_step + strlen(temp_word);
					ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, temp_word /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
					if (ret == 0)
					{
						vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
					}
				}
				else if (strcmp("<MEC>", fst->arc[temp_arc_idx].itemp) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					read_a_utf8_word(sentence, temp_word, &temp_idx);
					// printf("1 %s\n", temp_word);
					if (isEnglish(temp_word) == 1 || isCJK_words(temp_word) == 1)
					{
						// printf("\t1 %s\n", temp_word);
						temp_step = vinfo->pre_state[pre_index]->forward_step + strlen(temp_word);
						ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, temp_word /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
						if (ret == 0)
						{
							vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
						}
					}
				}
				else if (strcmp("<NAN>", fst->arc[temp_arc_idx].itemp) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					read_a_utf8_word(sentence, temp_word, &temp_idx);
					// printf("1 %s\n", temp_word);
					if (isNumber(temp_word) == 0)
					{
						// printf("\t1 %s\n", temp_word);
						temp_step = vinfo->pre_state[pre_index]->forward_step + strlen(temp_word);
						ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, temp_word /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
						if (ret == 0)
						{
							vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
						}
					}
				}
				else if (strcmp("<LOOKBACK_NAE>", fst->arc[temp_arc_idx].itemp) == 0 ||
						 strcmp("<LOOKBACK_NAN>", fst->arc[temp_arc_idx].itemp) == 0 ||
						 strcmp("<LOOKBACK_IAN>", fst->arc[temp_arc_idx].itemp) == 0 ||
						 strcmp("<LOOKBACK_NACJK>", fst->arc[temp_arc_idx].itemp) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					if (Retreat_a_utf8_word(sentence, &temp_idx) == 0)
					{
						temp_word[0] = '\0';
					}
					else
					{
						read_a_utf8_word(sentence, temp_word, &temp_idx);
					}

					if ((isEnglish(temp_word) == 0 && strcmp("<LOOKBACK_NAE>", fst->arc[temp_arc_idx].itemp) == 0) ||
						(isNumber(temp_word) == 0 && strcmp("<LOOKBACK_NAN>", fst->arc[temp_arc_idx].itemp) == 0) ||
						(isNumber(temp_word) == 1 && strcmp("<LOOKBACK_IAN>", fst->arc[temp_arc_idx].itemp) == 0) ||
						(isCJK_words(temp_word) == 0 && strcmp("<LOOKBACK_NACJK>", fst->arc[temp_arc_idx].itemp) == 0))
					{
						temp_step = vinfo->pre_state[pre_index]->forward_step; // LOOKBACK not include the english char
						// printf("comp_idx=%d temp_idx=%d temp_step=%d temp_word=%s\n", comp_idx, temp_idx, temp_step, temp_word);
						ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
						if (ret == 0)
						{
							vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
						}
					}
					// printf("3 %d %d %s %d %d %d\n", start_idx, vinfo->pre_state[pre_index]->forward_step + (int)strlen(fst->arc[temp_arc_idx].itemp), fst->arc[temp_arc_idx].itemp, pre_index, cur_index, vinfo->pre_state[pre_index]->forward_step);
				}
				else if (strcmp("<LOOKAHEAD_NAE>", fst->arc[temp_arc_idx].itemp) == 0 ||
						 strcmp("<LOOKAHEAD_NAN>", fst->arc[temp_arc_idx].itemp) == 0 ||
						 strcmp("<LOOKAHEAD_IAN>", fst->arc[temp_arc_idx].itemp) == 0 ||
						 strcmp("<LOOKAHEAD_NACJK>", fst->arc[temp_arc_idx].itemp) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					read_a_utf8_word(sentence, temp_word, &temp_idx);
					if ((isEnglish(temp_word) == 0 && strcmp("<LOOKAHEAD_NAE>", fst->arc[temp_arc_idx].itemp) == 0) ||
						(isNumber(temp_word) == 0 && strcmp("<LOOKAHEAD_NAN>", fst->arc[temp_arc_idx].itemp) == 0) ||
						(isNumber(temp_word) == 1 && strcmp("<LOOKAHEAD_IAN>", fst->arc[temp_arc_idx].itemp) == 0) ||
						(isCJK_words(temp_word) == 0 && strcmp("<LOOKAHEAD_NACJK>", fst->arc[temp_arc_idx].itemp) == 0))
					{
						temp_step = vinfo->pre_state[pre_index]->forward_step; // LOOKAHEAD not include the english char
						ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
						if (ret == 0)
						{
							vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
						}
					}
					// printf("2 %d %d %s %d %d %d\n", start_idx, vinfo->pre_state[pre_index]->forward_step + (int)strlen(fst->arc[temp_arc_idx].itemp), fst->arc[temp_arc_idx].itemp, pre_index, cur_index, vinfo->pre_state[pre_index]->forward_step);
				}
				else if (strcmp("<LOOKAHEAD2_NAN>", fst->arc[temp_arc_idx].itemp) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					read_a_utf8_word(sentence, temp_word, &temp_idx);
					read_a_utf8_word(sentence, temp_word, &temp_idx);
					if ((isNumber(temp_word) == 0 && strcmp("<LOOKAHEAD2_NAN>", fst->arc[temp_arc_idx].itemp) == 0))
					{
						temp_step = vinfo->pre_state[pre_index]->forward_step; // LOOKAHEAD not include the english char
						ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
						if (ret == 0)
						{
							vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
						}
					}
					// printf("2 %d %d %s %d %d %d\n", start_idx, vinfo->pre_state[pre_index]->forward_step + (int)strlen(fst->arc[temp_arc_idx].itemp), fst->arc[temp_arc_idx].itemp, pre_index, cur_index, vinfo->pre_state[pre_index]->forward_step);
				}
				else if (strncmp("<LOOKBACK_IS_NOT_", fst->arc[temp_arc_idx].itemp, 17) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					if (strcmp("<LOOKBACK_IS_NOT_SLASH>", fst->arc[temp_arc_idx].itemp) == 0)
					{

						if (Retreat_a_utf8_word(sentence, &temp_idx) != 0)
						{
							read_a_utf8_word(sentence, temp_word, &temp_idx);
						}
						else
						{
							temp_word[0] = '\0';
						}
						if (isSlash(temp_word) == 0)
						{
							temp_step = vinfo->pre_state[pre_index]->forward_step;
							ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
							if (ret == 0)
							{
								vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
							}
						}
					}
					else if (strcmp("<LOOKBACK_IS_NOT_DASH>", fst->arc[temp_arc_idx].itemp) == 0)
					{

						if (Retreat_a_utf8_word(sentence, &temp_idx) != 0)
						{
							read_a_utf8_word(sentence, temp_word, &temp_idx);
						}
						else
						{
							temp_word[0] = '\0';
						}
						if (isDash(temp_word) == 0)
						{
							temp_step = vinfo->pre_state[pre_index]->forward_step;
							ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
							if (ret == 0)
							{
								vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
							}
						}
					}
				}
				else if (strncmp("<LOOKBACK_IS_", fst->arc[temp_arc_idx].itemp, 13) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					compare_end_index = strlen(fst->arc[temp_arc_idx].itemp) - 1;
					compare_length = compare_end_index - 13;
					if (temp_idx - compare_length >= 0)
					{
						// printf("YES %s %d %d %s %s\n", &fst->arc[temp_arc_idx].itemp[14], compare_length, strncmp(&fst->arc[temp_arc_idx].itemp[13], &sentence[temp_idx - compare_length], compare_length), &fst->arc[temp_arc_idx].itemp[13], &sentence[temp_idx - compare_length]);
						if (strncmp(&fst->arc[temp_arc_idx].itemp[13], &sentence[temp_idx - compare_length], compare_length) == 0)
						{
							temp_step = vinfo->pre_state[pre_index]->forward_step; // LOOKBACK not include the english char
							// printf("comp_idx=%d temp_idx=%d temp_step=%d temp_word=%s\n", comp_idx, temp_idx, temp_step, temp_word);
							ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
							if (ret == 0)
							{
								vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
							}
						}
					}
				}
				else if (strncmp("<LOOKAHEAD_IS_NOT_", fst->arc[temp_arc_idx].itemp, 18) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					if (strcmp("<LOOKAHEAD_IS_NOT_DASH_and_TILDE>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_NOT_NUMBER_SIGN>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_NOT_DOT>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_NOT_SLASH>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_NOT_PERCENTAGE>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_NOT_COLON>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_NOT_COMMA>", fst->arc[temp_arc_idx].itemp) == 0)
					{
						// printf("%d %s\n", temp_arc_idx, fst->arc[temp_arc_idx].itemp);
						if (read_a_utf8_word(sentence, temp_word, &temp_idx) == 0)
						{
							Retreat_a_utf8_word(sentence, &temp_idx);
						}
						if ((isDash(temp_word) == 0 && isTilde(temp_word) == 0 && strcmp("<LOOKAHEAD_IS_NOT_DASH_and_TILDE>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isNumber_sign(temp_word) == 0 && strcmp("<LOOKAHEAD_IS_NOT_NUMBER_SIGN>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isDot(temp_word) == 0 && strcmp("<LOOKAHEAD_IS_NOT_DOT>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isSlash(temp_word) == 0 && strcmp("<LOOKAHEAD_IS_NOT_SLASH>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isPercentage(temp_word) == 0 && strcmp("<LOOKAHEAD_IS_NOT_PERCENTAGE>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isColon(temp_word) == 0 && strcmp("<LOOKAHEAD_IS_NOT_COLON>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isComma(temp_word) == 0 && strcmp("<LOOKAHEAD_IS_NOT_COMMA>", fst->arc[temp_arc_idx].itemp) == 0))
						{
							temp_step = vinfo->pre_state[pre_index]->forward_step;
							ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
							if (ret == 0)
							{
								vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
							}
						}
					}
					// have not been test...
					else
					{
						compare_end_index = strlen(fst->arc[temp_arc_idx].itemp) - 1;
						compare_length = compare_end_index - 18;
						if (temp_idx + compare_length < strlen(sentence))
						{
							if (strncmp(&fst->arc[temp_arc_idx].itemp[18], &sentence[temp_idx], compare_length) != 0)
							{
								temp_step = vinfo->pre_state[pre_index]->forward_step;
								ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
								if (ret == 0)
								{
									//printf("%d\n",cur_index);
									vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
								}
							}
						}
						else
						{
							temp_step = vinfo->pre_state[pre_index]->forward_step;
							ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
							if (ret == 0)
							{
								//printf("%d\n",cur_index);
								vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
							}
						}
					}
				}
				else if (strncmp("<LOOKAHEAD_IS_", fst->arc[temp_arc_idx].itemp, 14) == 0)
				{
					temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
					if (strcmp("<LOOKAHEAD_IS_DASH_or_TILDE>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_NUMBER_SIGN>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_DOT>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_SLASH>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_PERCENTAGE>", fst->arc[temp_arc_idx].itemp) == 0 ||
						strcmp("<LOOKAHEAD_IS_COMMA>", fst->arc[temp_arc_idx].itemp) == 0)
					{
						// printf("%d %s\n", temp_arc_idx, fst->arc[temp_arc_idx].itemp);
						if (read_a_utf8_word(sentence, temp_word, &temp_idx) == 0)
						{
							Retreat_a_utf8_word(sentence, &temp_idx);
						}
						if (((isDash(temp_word) == 1 || isTilde(temp_word) == 1) && strcmp("<LOOKAHEAD_IS_DASH_or_TILDE>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isNumber_sign(temp_word) == 1 && strcmp("<LOOKAHEAD_IS_NUMBER_SIGN>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isDot(temp_word) == 1 && strcmp("<LOOKAHEAD_IS_DOT>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isSlash(temp_word) == 1 && strcmp("<LOOKAHEAD_IS_SLASH>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isPercentage(temp_word) == 1 && strcmp("<LOOKAHEAD_IS_PERCENTAGE>", fst->arc[temp_arc_idx].itemp) == 0) ||
							(isComma(temp_word) == 1 && strcmp("<LOOKAHEAD_IS_COMMA>", fst->arc[temp_arc_idx].itemp) == 0))
						{
							temp_step = vinfo->pre_state[pre_index]->forward_step;
							ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
							if (ret == 0)
							{
								vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
							}
						}
					}
					// have not been test...
					else
					{
						compare_end_index = strlen(fst->arc[temp_arc_idx].itemp) - 1;
						compare_length = compare_end_index - 14;
						if (temp_idx + compare_length < strlen(sentence))
						{
							if (strncmp(&fst->arc[temp_arc_idx].itemp[14], &sentence[temp_idx], compare_length) == 0)
							{
								temp_step = vinfo->pre_state[pre_index]->forward_step;
								ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, "" /*fst->arc[temp_arc_idx].itemp*/, fst->arc[temp_arc_idx].otemp, temp_step);
								if (ret == 0)
								{
									vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
								}
							}
						}
					}
				}
			}
			// printf("%d kind_of_regular_input_length=%d\n", pre_index, fst->aiit.kind_of_regular_input_length[pre_index]);
			for (j = 0; j < fst->aiit.kind_of_regular_input_length[pre_index]; j++)
			{
				// printf("pre_index=%d\n", pre_index);
				temp_idx = comp_idx + vinfo->pre_state[pre_index]->forward_step;
				ret = bin_string_search_len_match(&sentence[temp_idx], &fst->aiit.regular_inputs[fst->aiit.each_regular_input_length_start_idx[fst->aiit.state_regular_input_length[pre_index][j] - 1]], fst->aiit.each_regular_input_length_word_number[fst->aiit.state_regular_input_length[pre_index][j] - 1]);
				// printf("%s ret=%d\n", &sentence[temp_idx], ret);
				if (ret != -1)
				{
					temp_input_idx = ret + fst->aiit.each_regular_input_length_start_idx[fst->aiit.state_regular_input_length[pre_index][j] - 1];
					// printf("%d %d %d %d %s\n", pre_index, temp_idx, comp_idx, vinfo->pre_state[pre_index]->forward_step, &sentence[temp_idx]);
					// printf("fst->aiit.possible_forward[pre_index][temp_input_idx]=%d\n", fst->aiit.possible_forward[pre_index][temp_input_idx]);
					for (k = 0; k < fst->aiit.possible_forward[pre_index][temp_input_idx]; k++)
					{
						temp_arc_idx = fst->aiit.forward_arcs[pre_index][temp_input_idx][k];
						// printf("\t%d %d %s %s\n", pre_index, temp_arc_idx, fst->aiit.regular_inputs[temp_input_idx], &sentence[temp_idx]);
						cur_index = fst->arc[temp_arc_idx].ostate;
						ret = fill_osym(&vinfo->pre_state[pre_index], &vinfo->cur_state[cur_index], depth + 1, cur_index, fst->arc[temp_arc_idx].itemp, fst->arc[temp_arc_idx].otemp, vinfo->pre_state[pre_index]->forward_step + strlen(fst->arc[temp_arc_idx].itemp));
						if (ret == 0)
						{
							vinfo->sur_cur_state[num_sur_cur_state++] = cur_index;
						}
					}
				}
			}
		}

		if (num_sur_cur_state == 0)
		{
			if ((fill_nsw(nsw, fst, vinfo->pre_state, num_sur_pre_state, vinfo->sur_pre_state, sentence, word, idx, start_idx, &replace_flag) == 1 || Retreat_flag == 1) && *idx != strlen(sentence))
			{
				// printf("h2 %s\n", nsw->token[nsw->size - 1]);
				// printf("%s %d\t%s,%d\t%d\n", sentence, strlen(sentence), nsw->token[nsw->size - 1], strlen(nsw->token[nsw->size - 1]), *idx);fflush(stdout);
				Retreat_a_utf8_word(sentence, idx);
				// printf("%s %d\t%s,\t%d\n", sentence, strlen(sentence), nsw->token[nsw->size - 1], *idx);fflush(stdout);
			}

			for (j = 0; j < num_sur_pre_state; j++)
			{
				if(vinfo->pre_state[vinfo->sur_pre_state[j]]->num_forward==0)
				{
					vinfo->is_head[vinfo->sur_pre_state[j]] = 1;
				}
				else
				{
					vinfo->is_head[vinfo->sur_pre_state[j]] = 0;
				}
			}
			for (j = 0; j < num_sur_pre_state; j++)
			{
				// printf("%d sur_pre_state[j]=%d outside=%d %s\n", j, vinfo->sur_pre_state[j], vinfo->pre_state[vinfo->sur_pre_state[j]]->num_forward, vinfo->pre_state[vinfo->sur_pre_state[j]]->input);
				if(vinfo->is_head[vinfo->sur_pre_state[j]] == 1)
				{
					destroy_osym(vinfo->pre_state[vinfo->sur_pre_state[j]]);
				}
			}
			// printf("%d %s %s\n", nsw->size, nsw->token[nsw->size - 1], nsw->rule[nsw->size - 1]);
			flag = 1;
			break;
		}
		if (fill_nsw(nsw, fst, vinfo->pre_state, num_sur_pre_state, vinfo->sur_pre_state, sentence, word, idx, start_idx, &replace_flag) == 1 && *idx != strlen(sentence))
		{
			// printf("h1 %s\n", nsw->token[nsw->size - 1]);
			Retreat_flag = 1;
			// Retreat_a_utf8_word(sentence, idx);
		}

		for (j = 0; j < num_sur_pre_state; j++)
		{
			if(vinfo->pre_state[vinfo->sur_pre_state[j]]->num_forward==0)
			{
				vinfo->is_head[vinfo->sur_pre_state[j]] = 1;
			}
			else
			{
				vinfo->is_head[vinfo->sur_pre_state[j]] = 0;
			}
		}
		for (j = 0; j < num_sur_pre_state; j++)
		{
			// printf("%d sur_pre_state[j]=%d outside=%d %s is_eps_input=%d\n", j, vinfo->sur_pre_state[j], vinfo->pre_state[vinfo->sur_pre_state[j]]->num_forward, vinfo->pre_state[vinfo->sur_pre_state[j]]->input, vinfo->pre_state[vinfo->sur_pre_state[j]]->is_eps_input);
			if(vinfo->is_head[vinfo->sur_pre_state[j]] == 1)
			{
				destroy_osym(vinfo->pre_state[vinfo->sur_pre_state[j]]);
			}
			vinfo->pre_state[vinfo->sur_pre_state[j]] = NULL;
		}
		// for (j = 0; j < num_sur_cur_state; j++)
		//{
		//	vinfo->sur_pre_state[j] = vinfo->sur_cur_state[j];
		// }
		temp_sur_state_osym = vinfo->cur_state;
		vinfo->cur_state = vinfo->pre_state;
		vinfo->pre_state = temp_sur_state_osym;
		for (j = 0; j < num_sur_cur_state; j++)
		{
			// vinfo->pre_state[vinfo->sur_cur_state[j]] = vinfo->cur_state[vinfo->sur_cur_state[j]];
			vinfo->cur_state[vinfo->sur_cur_state[j]] = NULL;
		}
		temp_sur_state_num = vinfo->sur_cur_state;
		vinfo->sur_cur_state = vinfo->sur_pre_state;
		vinfo->sur_pre_state = temp_sur_state_num;

		num_sur_pre_state = num_sur_cur_state;

		/*printf("%s num_sur_cur_state=%d\n", word, num_sur_cur_state);
		for (j = 0; j < num_sur_pre_state && depth >= 5; j++)
		{
			temp = vinfo->pre_state[vinfo->sur_pre_state[j]];
			for (; (*temp).from != NULL;)
			{
				printf("(%d %d)", (*temp).state, (*temp).num_forward);
				temp = (*temp).from;
			}
			printf("\n");
		}
		PAUSE_AND_CONTINUE*/
	}
	if (flag == 1)
	{
		read_a_utf8_word(sentence, word, idx);
		// printf("herehere : %s\n", word);
		// fflush(stdout);
	}
	if (nsw->size > 0)
	{
		nsw->language[nsw->size - 1] = decide_language_by_sentence(sentence, nsw);
	}
}
void initial_viterbi_info(FST *fst, VITERBIINFO *vinfo)
{
	vinfo->len = fst->num_state;
	vinfo->cur_state = (OSYM **)malloc(vinfo->len * sizeof(OSYM *));
	vinfo->pre_state = (OSYM **)malloc(vinfo->len * sizeof(OSYM *));
	vinfo->sur_cur_state = (int *)malloc(vinfo->len * sizeof(int));
	vinfo->sur_pre_state = (int *)malloc(vinfo->len * sizeof(int));
	vinfo->is_head = (int *)malloc(vinfo->len * sizeof(int));
}
void destroy_viterbi_info(VITERBIINFO *vinfo)
{
	free(vinfo->cur_state);
	free(vinfo->pre_state);
	free(vinfo->sur_cur_state);
	free(vinfo->sur_pre_state);
	free(vinfo->is_head);
}

int fill_osym(OSYM **pre, OSYM **next, int depth, int state, char *input, char *output, int step)
{
	OSYM *temp;
	char empty[2] = "";
	char *real_input;
	
	real_input = &empty[0];

	if (strcmp(input, "<eps>") == 0)
	{
		if ((*pre) != NULL)
		{
			real_input = (*pre)->input;
		}
	}
	else
	{
		real_input = input;
	}
	// printf("%d %s real=%s\n", state, input, real_input);

	if ((*next) != NULL)
	{
		if (strlen((*next)->input) < strlen(real_input) || (real_input[0] == '\0' && (*next)->input[0] == '\0'))
		{
			(*next)->output = (char *)realloc((*next)->output, (strlen(output) + 1) * sizeof(char));
			strcpy((*next)->output, output);
			(*next)->input = (char *)realloc((*next)->input, (strlen(real_input) + 1) * sizeof(char));
			strcpy((*next)->input, real_input);
			(*next)->forward_step = step;
			if ((*next)->from != NULL && (*next)->from != *pre)
			{
				(*next)->from->num_forward--;
			}
			if (*pre != NULL && (*next)->from != *pre)
			{
				(*pre)->num_forward++;
			}
			if (*pre == NULL)
			{
				(*next)->from = NULL;
			}
			else
			{
				(*next)->from = *pre;
			}
			if (strcmp(input, "<eps>") == 0)
			{
				(*next)->is_eps_input = 1;
			}
		}
		return 1;
	}
	else
	{
		temp = (OSYM *)malloc(sizeof(OSYM));
		temp->depth = depth;
		if (*pre != NULL)
		{
			(*pre)->num_forward++;
			temp->from = *pre;
		}
		else
		{
			temp->from = NULL;
		}
		temp->state = state;
		temp->num_forward = 0;
		temp->output = (char *)malloc((strlen(output) + 1) * sizeof(char));
		strcpy(temp->output, output);
		temp->input = (char *)malloc((strlen(real_input) + 1) * sizeof(char));
		strcpy(temp->input, real_input);
		temp->forward_step = step;
		temp->is_eps_input = 0;
		if (strcmp(input, "<eps>") == 0)
		{
			temp->is_eps_input = 1;
		}
		*next = temp;
	}

	return 0;
}
void destroy_osym(OSYM *head)
{
	OSYM *temp1, *temp2;
	int is_eps_input;

	for (temp1 = head; temp1 != NULL;)
	{
		// printf("here %d input=%s depth=%d num_forward=%d\n", temp1->state, temp1->input, temp1->depth, temp1->num_forward);
		//fflush(stdout);
		if (temp1->num_forward == 0)
		{
			// printf("WTF!!!!!!!!!!!!!!!!!!!!!\n");
			// printf("input=%s free %u depth=%d\n", temp1->input, temp1->state, temp1->depth);
			temp2 = (*temp1).from;
			if (temp2 != NULL)
			{
				(*temp2).num_forward--;
			}
			is_eps_input = (*temp1).is_eps_input;
			free((*temp1).output);
			free((*temp1).input);
			free(temp1);
			//if (is_eps_input == 1)
			//{
			//	break;
			//}
			temp1 = temp2;
		}
		else
		{
			break;
		}
	}
}
int fill_nsw(NSW_TOKEN *nsw, FST *fst, OSYM **head, int num_sur_state, int *sur_state, char *sentence, char *word, int *read_idx, int statr_idx, int *replace_flag)
{
	int i, j, externed_cap;
	int possible_state, ending_state = -1;
	int ending_idx;
	OSYM *temp;

	for (i = 0; i < num_sur_state && ending_state == -1; i++)
	{
		possible_state = sur_state[i];
		// printf("possible_state = %d\n", possible_state);
		for (j = 0; j < fst->num_end; j++)
		{
			if (possible_state == fst->end_state[j])
			{
				ending_state = possible_state;
				break;
			}
		}
	}
	if (ending_state == -1)
	{
		return 0;
	}

	if (*replace_flag == 1)
	{
		if ((int)strlen(nsw->token[nsw->size - 1]) > head[ending_state]->forward_step)
		{
			return 0;
		}
		// printf("%d %s %d\n",*read_idx, nsw->token[nsw->size - 1], (int)strlen(nsw->token[nsw->size - 1]));
		*read_idx = *read_idx - strlen(nsw->token[nsw->size - 1]) + head[ending_state]->forward_step;
		nsw->end_idx[nsw->size - 1] = *read_idx;
		nsw->token[nsw->size - 1] = (char *)realloc(nsw->token[nsw->size - 1], (nsw->end_idx[nsw->size - 1] - nsw->start_idx[nsw->size - 1] + 2) * sizeof(char));
		for (i = 0; i + nsw->start_idx[nsw->size - 1] < nsw->end_idx[nsw->size - 1]; i++)
		{
			nsw->token[nsw->size - 1][i] = sentence[i + nsw->start_idx[nsw->size - 1]];
		}
		nsw->token[nsw->size - 1][i] = '\0';
		for (temp = head[ending_state]; temp != NULL; temp = (*temp).from)
		{
			if (strcmp((*temp).output, "<eps>") != 0)
			{
				nsw->rule[nsw->size - 1] = (char *)realloc(nsw->rule[nsw->size - 1], (strlen((*temp).output) + 1) * sizeof(char));
				strcpy(nsw->rule[nsw->size - 1], (*temp).output);
				break;
			}
		}
		// printf("%d %s %d\n", *read_idx, nsw->token[nsw->size - 1], (int)strlen(nsw->token[nsw->size - 1]));
	}
	else
	{
		*read_idx += head[ending_state]->forward_step;
		// printf("sentence = %s,\tstatr_idx=%d,\tread_idx=%d\n", sentence, statr_idx, *read_idx);
		// fflush(stdout);
		ending_idx = *read_idx;
		nsw->start_idx[nsw->size] = statr_idx;
		/*if (word[0] != '\0')
		{
			Retreat_a_utf8_word(sentence, &ending_idx);
		}*/
		nsw->end_idx[nsw->size] = ending_idx;

		nsw->token[nsw->size] = (char *)realloc(nsw->token[nsw->size], (nsw->end_idx[nsw->size] - nsw->start_idx[nsw->size] + 2) * sizeof(char));
		for (i = 0; i + nsw->start_idx[nsw->size] < nsw->end_idx[nsw->size]; i++)
		{
			nsw->token[nsw->size][i] = sentence[i + nsw->start_idx[nsw->size]];
		}
		nsw->token[nsw->size][i] = '\0';

		for (temp = head[ending_state]; temp != NULL; temp = (*temp).from)
		{
			if (strcmp((*temp).output, "<eps>") != 0)
			{
				nsw->rule[nsw->size] = (char *)realloc(nsw->rule[nsw->size], (strlen((*temp).output) + 1) * sizeof(char));
				strcpy(nsw->rule[nsw->size], (*temp).output);
				break;
			}
		}
		// printf("nsw->token = %s,\tnsw->rule[nsw->size] = %s\n", nsw->token[nsw->size], nsw->rule[nsw->size]);
		nsw->size++;

		if (nsw->size == nsw->capacity)
		{
			externed_cap = nsw->capacity + NUM_EXTERN;
			nsw->rule = (char **)realloc(nsw->rule, externed_cap * sizeof(char *));
			nsw->end_idx = (int *)realloc(nsw->end_idx, externed_cap * sizeof(int));
			nsw->start_idx = (int *)realloc(nsw->start_idx, externed_cap * sizeof(int));
			nsw->language = (int *)realloc(nsw->language, externed_cap * sizeof(int));
			nsw->token = (char **)realloc(nsw->token, externed_cap * sizeof(char *));
			nsw->SFW = (char **)realloc(nsw->SFW, externed_cap * sizeof(char *));
			for (i = nsw->capacity; i < externed_cap; i++)
			{
				nsw->rule[i] = (char *)malloc(sizeof(char));
				nsw->token[i] = (char *)malloc(sizeof(char));
				nsw->SFW[i] = (char *)malloc(sizeof(char));
			}
			nsw->capacity = externed_cap;
		}

		*replace_flag = 1;
	}

	return 1;
}
void load_text(FILE *fin, TEXT *text_in)
{
	int FILEEND, capacity_of_line = 0;
	char *line = (char *)malloc(sizeof(char));
	int i, num_line;

	for (num_line = 0, FILEEND = 0; FILEEND == 0;)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, fin);
		num_line++;
	}
	text_in->num_of_sentence = num_line;
	fseek(fin, 0, SEEK_SET);
	text_in->sentence = (char **)malloc(text_in->num_of_sentence * sizeof(char *));
	for (i = 0, FILEEND = 0; FILEEND == 0;)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, fin);
		text_in->sentence[i] = (char *)malloc((strlen(line) + 1) * sizeof(char));
		strcpy(text_in->sentence[i++], line);
	}

	free(line);
}
void load_flags(FILE *fflags, FLAGS *flags)
{
	int FILEEND, capacity_of_line = 0;
	char *line = (char *)malloc(sizeof(char));
	char *token = (char *)malloc(sizeof(char));
	int i, j, k, len;

	for (flags->size = 0, FILEEND = 0; FILEEND == 0;)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, fflags);
		if (line[0] != '\0' && line[0] != '#')
		{
			flags->size++;
		}
	}
	flags->token = (FLAG_TOKEN *)malloc(flags->size * sizeof(FLAG_TOKEN));
	fseek(fflags, 0, SEEK_SET);
	for (i = 0, FILEEND = 0; FILEEND == 0;)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, fflags);
		if (line[0] != '\0' && line[0] != '#')
		{
			token = (char *)realloc(token, (capacity_of_line + 1) * sizeof(char));
			for (j = 0, len = strlen(line); j < len; j++)
			{
				if (line[j] == '#')
				{
					if (j > 0)
					{
						if (line[j - 1] == '\\')
						{
							break;
						}
					}
					line[j] = '\0';
					break;
				}
			}
			for (j = k = 0; line[j] != ' ' && line[j] != '\t'; j++)
			{
				token[k++] = line[j];
			}
			token[k] = '\0';
			flags->token[i].rules = (char *)malloc((strlen(token) + 1) * sizeof(char));
			strcpy(flags->token[i].rules, token);
			for (; line[j] == ' ' || line[j] == '\t'; j++)
			{
			}
			for (k = 0; line[j] != ' ' && line[j] != '\t'; j++)
			{
				token[k++] = line[j];
			}
			token[k] = '\0';
			if (strcmp(token, "=") != 0)
			{
				printf("flags configure error: row%d %s\n", i + 1, line);
				exit(1);
			}
			for (; line[j] == ' ' || line[j] == '\t'; j++)
			{
			}
			for (k = 0; line[j] != ' ' && line[j] != '\t'; j++)
			{
				token[k++] = line[j];
			}
			token[k] = '\0';
			if (strcmp(token, "0") != 0 && strcmp(token, "1") != 0)
			{
				printf("flags configure error: row%d %s\n", i + 1, line);
				exit(1);
			}
			flags->token[i++].on = token[0] - 48;
		}
	}
	/*printf("size=%d\n", flags->size);
	for (i = 0; i < flags->size; i++)
	{
		printf("%s %d\n", flags->token[i].rules, flags->token[i].on);
	}*/
	qsort(flags->token, flags->size, sizeof(FLAG_TOKEN), flagscomparefun);
	/*printf("size=%d\n", flags->size);
	for (i = 0; i < flags->size; i++)
	{
		printf("%s %d\n", flags->token[i].rules, flags->token[i].on);
	}*/

	free(line);
	free(token);
}
void normalize_number(char *num_in, char *num_out)
{
	int i, idx, length, num_len;
	char word[7];

	for (num_out[0] = '\0', idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			continue;
		}
		if (strlen(word) == 1) // half_type
		{
			strcat(num_out, word);
		}
		else // fully_type
		{
			word[0] = word[2] + 112 + 48;
			word[1] = '\0';
			strcat(num_out, word);
		}
	}
}
void normalize_number_float(char *num_in, char *num_out)
{
	int i, idx, length, num_len;
	char word[7];

	for (num_out[0] = '\0', idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if(isDot(word) == 1)
		{
			strcat(num_out, ".");
		}
		else if (isNumber(word) == 1)
		{
			if (strlen(word) == 1) // half_type
			{
				strcat(num_out, word);
			}
			else // fully_type
			{
				word[0] = word[2] + 112 + 48;
				word[1] = '\0';
				strcat(num_out, word);
			}
		}
	}
}
void NTNSFW(char *num_in, char *NSPW, int decide_spoken_type)
{
	int i, length, order, connect_zero;
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	int pending_len, remainder, all_zero;
	char pending_number[5];

	normalize_number(num_in, temp);
	for (length = strlen(temp); temp[0] == '0' && length > 1; length = strlen(temp))
	{ // remove Superfluous zero
		for (i = 0; i < length; i++)
		{
			temp[i] = temp[i + 1];
		}
	}

	for (order = 2, length = strlen(temp); length - 4 > 0; order++)
	{
		length -= 4;
	}
	if (order > 14)
	{
		normalize_number(num_in, temp);
		NTISFW(temp, NSPW, 0);
		free(temp);
		return;
	}

	for (length = strlen(temp), NSPW[0] = '\0', connect_zero = 0, all_zero = 1;
		 length > 0; length -= pending_len, order--, all_zero = 1)
	{
		remainder = length - ((int)(length / 4)) * 4;
		pending_len = remainder > 0 ? remainder : 4;
		strncpy(pending_number, temp, pending_len);
		pending_number[pending_len] = '\0';
		for (i = 0; i + pending_len <= length; i++)
		{
			temp[i] = temp[i + pending_len];
		}
		// printf("%d %d %s\t", length, pending_len, pending_number);
		switch (pending_len)
		{
		case 1:
			if (pending_number[0] == '2' && decide_spoken_type == 1)
			{
				strcat(NSPW, two_for_measure_word);
			}
			else
			{
				strcat(NSPW, CH_number[pending_number[0] - 48]);
			}
			if (order > 2)
			{
				strcat(NSPW, UNIT[order]);
			}
			break;
		case 2:
			if (pending_number[0] != '1')
			{
				strcat(NSPW, CH_number[pending_number[0] - 48]);
			}
			strcat(NSPW, UNIT[0]);
			if (pending_number[1] != '0')
			{
				strcat(NSPW, CH_number[pending_number[1] - 48]);
			}
			else
			{
				connect_zero = 1;
			}
			if (order > 2)
			{
				strcat(NSPW, UNIT[order]);
			}
			break;
		case 3:
			if (pending_number[0] == '2')
			{
				strcat(NSPW, two_for_measure_word);
			}
			else
			{
				strcat(NSPW, CH_number[pending_number[0] - 48]);
			}
			strcat(NSPW, UNIT[1]);
			if (pending_number[1] != '0')
			{
				strcat(NSPW, CH_number[pending_number[1] - 48]);
				strcat(NSPW, UNIT[0]);
			}
			if (pending_number[2] != '0')
			{
				if (pending_number[1] != '0')
				{
					strcat(NSPW, CH_number[pending_number[2] - 48]);
				}
				else
				{
					strcat(NSPW, CH_number[0]);
					strcat(NSPW, CH_number[pending_number[2] - 48]);
				}
			}
			else
			{
				connect_zero = 1;
			}
			if (order > 2)
			{
				strcat(NSPW, UNIT[order]);
			}
			break;
		case 4:
			if (pending_number[0] != '0')
			{
				if (connect_zero == 1)
				{
					strcat(NSPW, CH_number[0]);
					connect_zero = 0;
				}
				if (pending_number[0] == '2')
				{
					strcat(NSPW, two_for_measure_word);
				}
				else
				{
					strcat(NSPW, CH_number[pending_number[0] - 48]);
				}
				strcat(NSPW, UNIT[2]);
				all_zero = 0;
			}
			else
			{
				connect_zero = 1;
			}
			/************************************************************/
			if (pending_number[1] != '0')
			{
				if (connect_zero == 1)
				{
					strcat(NSPW, CH_number[0]);
					connect_zero = 0;
				}
				if (pending_number[1] == '2')
				{
					strcat(NSPW, two_for_measure_word);
				}
				else
				{
					strcat(NSPW, CH_number[pending_number[1] - 48]);
				}
				strcat(NSPW, UNIT[1]);
				all_zero = 0;
			}
			else
			{
				connect_zero = 1;
			}
			/************************************************************/
			if (pending_number[2] != '0')
			{
				if (connect_zero == 1)
				{
					strcat(NSPW, CH_number[0]);
					connect_zero = 0;
				}
				strcat(NSPW, CH_number[pending_number[2] - 48]);
				strcat(NSPW, UNIT[0]);
				all_zero = 0;
			}
			else
			{
				connect_zero = 1;
			}
			/************************************************************/
			if (pending_number[3] != '0')
			{
				if (connect_zero == 1)
				{
					strcat(NSPW, CH_number[0]);
					connect_zero = 0;
				}
				strcat(NSPW, CH_number[pending_number[3] - 48]);
				all_zero = 0;
			}
			else
			{
				connect_zero = 1;
			}
			if (order > 2 && all_zero == 0)
			{
				strcat(NSPW, UNIT[order]);
			}
			break;
		default:
			break;
		}
	}

	free(temp);
}
void NTISFW(char *num_in, char *ISPW, int language_code)
{
	int i, len;
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	normalize_number(num_in, temp);

	for (i = 0, len = strlen(temp), ISPW[0] = '\0'; i < len; i++)
	{
		strcat(ISPW, CH_number[temp[i] - 48]);
	}

	free(temp);
}
void DPTSFW(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp;

	if (language_code == 2)
	{
		DPESFW(num_in, DPSPW);
		return;
	}

	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (strcmp(word, "0") == 0 || strcmp(word, Number[10]) == 0)
		{
			continue;
		}
		else if (isDot(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		else
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
	}
	if (idx == strlen(num_in))
	{
		Retreat_a_utf8_word(num_in, &idx);
	}
	// for (idx = 0; num_in[idx] == '0' && num_in[idx + 1] != '.' && num_in[idx + 1] != '\0'; idx++)
	//{
	//	continue;
	// }
	// printf("%s %d\n", num_in, idx);

	for (i = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDot(word) == 0 && (isNumber(word) == 1 || isComma(word) == 1))
		{
			strcat(temp, word);
			i++;
		}
		else
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
	}
	// for (i = 0; num_in[idx] != '.' && num_in[idx] != '\0'; idx++)
	//{
	//
	//	temp[i++] = num_in[idx];
	// }
	// temp[i] = '\0';
	// printf("%d %s\n", i, temp);
	if (i == 1)
	{
		NTNSFW(temp, DPSPW, 0);
	}
	else
	{
		NTNSFW(temp, DPSPW, 1);
	}

	if (num_in[idx] == '\0')
	{
		free(temp);
		return;
	}

	for (i = 0, idx++; num_in[i + idx] != '\0'; i++)
	{
		temp[i] = num_in[i + idx];
	}
	temp[i] = '\0';
	if (has_number(temp) == 1)
	{
		strcat(DPSPW, CH_point);
		NTISFW(temp, &DPSPW[strlen(DPSPW)], language_code);
	}

	free(temp);
}
void NWMSFW(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp;
	char *prefix;
	char *prefix_free_num_in;
	char *unit, *removespace_unit;

	if (has_dot_numerals(num_in) == 1)
	{
		for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isNumber(word) == 1)
			{
				Retreat_a_utf8_word(num_in, &idx);
				N2SWND(&num_in[idx], &DPSPW[strlen(DPSPW)], 1);
				return;
			}
			else if (isDash(word) == 1)
			{
				strcat(DPSPW, ch_negative);
			}
			else
			{
				strcat(DPSPW, word);
			}
		}
	}

	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	unit = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	removespace_unit = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	prefix = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	prefix_free_num_in = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0, temp[0] = unit[0] = removespace_unit[0] = prefix[0] = prefix_free_num_in[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			strcpy(prefix_free_num_in, &num_in[idx]);
			break;
		}
		strcat(prefix, word);
	}
	for (idx = 0; read_a_utf8_word(prefix, word, &idx) == 0;)
	{
		if (isDash(word) == 1)
		{
			strcat(DPSPW, ch_negative);
		}
		else
		{
			strcat(DPSPW, word);
		}
	}

	for (idx = 0; read_a_utf8_word(prefix_free_num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isComma(word) == 0 && isDot(word) == 0)
		{
			break;
		}
	}
	if (word[0] != '\0')
	{
		Retreat_a_utf8_word(prefix_free_num_in, &idx);
	}
	strncpy(temp, prefix_free_num_in, idx);
	temp[idx] = '\0';
	strcpy(unit, &(prefix_free_num_in[idx]));
	strcpy(removespace_unit, unit);
	remove_space(temp);
	remove_space(removespace_unit);
	//printf("num_in=%s prefix=%s prefix_free_num_in=%s temp=%s unit=%s removespace_unit=%s\n", num_in, prefix, prefix_free_num_in, temp, unit, removespace_unit);
	if (strcmp(removespace_unit, Mandarin_year) == 0 && utf8_word_length(temp) == 4)
	{
		fflush(stdout);
		STFNVI(temp, &DPSPW[strlen(DPSPW)]);
	}
	else if ((strcmp(removespace_unit, ch_zh4) == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, Mandarin_month) == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, Mandarin_day) == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, Mandarin_grade) == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, Mandarin_time) == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, Mandarin_number) == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, ch_floor) == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, "送") == 0 && utf8_word_length(temp) == 1) ||
			 (strcmp(removespace_unit, two_for_measure_word) == 0 && utf8_word_length(temp) == 1))
	{
		fflush(stdout);
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 0);
	}
	else if (strcmp(removespace_unit, Mandarin_discount) == 0)
	{
		fflush(stdout);
		NTISFW(temp, &DPSPW[strlen(DPSPW)], 0);
	}
	else
	{
		fflush(stdout);
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 1);
	}

	strcat(DPSPW, unit);

	free(temp);
	free(unit);
	free(removespace_unit);
	free(prefix);
	free(prefix_free_num_in);
}
int isspaces(char *word)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(word, spaces[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
void forward_until_not_space_and_tab(char *line, int *idx)
{
	char word[7];

	for (; read_a_utf8_word(line, word, idx) == 0;)
	{
		if (isspaces(word) == 0)
		{
			break;
		}
	}
	if (word[0] != '\0')
	{
		Retreat_a_utf8_word(line, idx);
	}
}
void load_rules(FILE *frul, RULES *rul)
{
	int FILEEND, capacity_of_line = 0;
	char *line = (char *)malloc(sizeof(char));
	char *temp1, *temp2, *tok = (char *)malloc(sizeof(char));
	int i, idx;

	for (FILEEND = idx = 0; FILEEND == 0; idx = 0)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, frul);
		forward_until_not_space_and_tab(line, &idx);
		temp1 = &line[idx];
		if (temp1[0] != '\0')
		{
			if (strncmp(temp1, "~r", 2) == 0)
			{
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				temp2 = &line[idx];
				if (strncmp(temp2, "substitution", 12) == 0)
				{
					idx += 12;
					forward_until_not_space_and_tab(line, &idx);
					temp2 = &line[idx];
					rul->sub.size = 0;
					rul->sub.capacity = atoi(temp2);
					// printf("%d\n",rul->sub.size);
					load_substitution(frul, &(rul->sub));
				}
				if (strncmp(temp2, "transformation", 14) == 0)
				{
					idx += 14;
					forward_until_not_space_and_tab(line, &idx);
					temp2 = &line[idx];
					rul->tra.size = 0;
					tok = (char *)realloc(tok, (strlen(line) + 1) * sizeof(char));

					for (i = 0; line[idx + i] != ' ' && line[idx + i] != '\t' && line[idx + i] != '\0'; i++)
					{
						tok[i] = line[idx + i];
					}
					tok[i] = '\0';
					rul->tra.capacity = atoi(tok);
					idx += i;
					forward_until_not_space_and_tab(line, &idx);

					// for (i = 0; line[idx + i] != ' ' && line[idx + i] != '\t' && line[idx + i] != '\0'; i++)
					//{
					//	tok[i] = line[idx + i];
					// }
					// tok[i] = '\0';
					// rul->tra.scale_size = atoi(tok);
					// idx += i;
					// forward_until_not_space_and_tab(line, &idx);
					//
					// for (i = 0; line[idx + i] != ' ' && line[idx + i] != '\t' && line[idx + i] != '\0'; i++)
					//{
					//	tok[i] = line[idx + i];
					//}
					// tok[i] = '\0';
					// rul->tra.extra_size = atoi(tok);
					// idx += i;
					// forward_until_not_space_and_tab(line, &idx);
					//
					// if (rul->tra.scale_size <= 0)
					//{
					//	printf("error: scale_size must be greater than 0.\n%s\n", line);
					//	exit(1);
					//}

					// printf("%d %d %d %d\n", rul->tra.size, rul->tra.capacity, rul->tra.scale_size, rul->tra.extra_size);
					load_transformation(frul, &(rul->tra));
				}
			}
		}
	}

	free(line);
	free(tok);
}
void load_transformation(FILE *frul, TRANSFORMATION *tra)
{
	int FILEEND, capacity_of_line = 0;
	char *line = (char *)malloc(sizeof(char));
	char *tok = (char *)malloc(sizeof(char));
	char *temp1;
	int i, j, idx, order = -1, len, temp_idx, language_code;
	int mapidx = 0, map_size = sizeof(fn_map) / sizeof(fn_map[0]);

	tra->rul = (TRANSFORMATION_RULES *)malloc(tra->capacity * sizeof(TRANSFORMATION_RULES));

	for (FILEEND = idx = 0; FILEEND == 0; idx = 0)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, frul);
		if (line[0] != '\0' && line[0] != '#')
		{
			forward_until_not_space_and_tab(line, &idx);
			temp1 = &line[idx];
			if (strncmp(temp1, "~c", 2) == 0)
			{
				if (tra->size >= tra->capacity)
				{
					continue;
				}
				tok = (char *)realloc(tok, (strlen(line) + 1) * sizeof(char));
				order++;
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				// printf("%s\n", temp1);
				for (temp_idx = idx; line[temp_idx] != ' ' && line[temp_idx] != '\t' && line[temp_idx] != '\0'; temp_idx++)
				{
				}
				tra->rul[order].scale_size = tra->rul[order].extra_size = 0;
				tra->rul[order].rp_capacicty = 0;
				tra->rul[order].rp_size = 0;
				tra->rul[order].rp = (REPLACE_PAIR *)malloc(sizeof(REPLACE_PAIR));
				tra->rul[order].prefix = (char **)malloc(2 * sizeof(char *));
				tra->rul[order].prefix[0] = (char *)malloc(sizeof(char));
				tra->rul[order].prefix[1] = (char *)malloc(sizeof(char));
				tra->rul[order].suffix = (char **)malloc(2 * sizeof(char *));
				tra->rul[order].suffix[0] = (char *)malloc(sizeof(char));
				tra->rul[order].suffix[1] = (char *)malloc(sizeof(char));
				tra->rul[order].template = (char *)malloc(sizeof(char));
				tra->rul[order].prefix[0][0] = tra->rul[order].prefix[1][0] = tra->rul[order].suffix[0][0] = tra->rul[order].suffix[1][0] = '\0';
				tra->rul[order].name = (char *)malloc((temp_idx - idx + 1) * sizeof(char));
				strncpy(tra->rul[order].name, &line[idx], temp_idx - idx);
				tra->rul[order].name[temp_idx - idx] = '\0';
				// printf("%s %d\n", tra->rul[order].name, strlen(tra->rul[order].name));
				idx = temp_idx;
				forward_until_not_space_and_tab(line, &idx);
				if (strncmp(&line[idx], "on", 2) == 0)
				{
					tra->rul[order].status = 1;
					idx += 2;
				}
				else if (strncmp(&line[idx], "off", 3) == 0)
				{
					tra->rul[order].status = 0;
					idx += 3;
				}
				else
				{
					printf("error: status should be on or off\n%s\n", line);
					exit(1);
				}
				forward_until_not_space_and_tab(line, &idx);
				for (temp_idx = idx, i = 0; line[temp_idx] != ' ' && line[temp_idx] != '\t' && line[temp_idx] != '\0'; temp_idx++)
				{
					tok[i++] = line[temp_idx];
				}
				tok[i] = 0;
				if ((tra->rul[order].scale_size = atoi(tok)) < 0)
				{
					printf("error: scale_size should be >= 0\n%s\n", line);
					exit(1);
				}
				idx = temp_idx;
				forward_until_not_space_and_tab(line, &idx);
				for (temp_idx = idx, i = 0; line[temp_idx] != ' ' && line[temp_idx] != '\t' && line[temp_idx] != '\0'; temp_idx++)
				{
					tok[i++] = line[temp_idx];
				}
				tok[i] = 0;
				if ((tra->rul[order].extra_size = atoi(tok)) < 0)
				{
					printf("error: extra_size should be >= 0\n%s\n", line);
					exit(1);
				}
				// printf("%s %d\n", tra->rul[order].name, tra->rul[order].status);
			}
			if (strncmp(temp1, "~k", 2) == 0)
			{
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				tra->rul[order].template = (char *)realloc(tra->rul[order].template, (strlen(temp1) + 1) * sizeof(char));
				strcpy(tra->rul[order].template, temp1);
				// printf("%s %d %s\n", tra->rul[order].name, tra->rul[order].status, tra->rul[order].template);
				for(mapidx = 0; mapidx < map_size; mapidx++){
					if (strcmp(tra->rul[order].template, fn_map[mapidx].name) == 0)
					{
						tra->rul[order].transfer_fn = fn_map[mapidx].fn;
						break;
					}
				}
				if(mapidx == map_size)
				{
					tra->rul[order].transfer_fn = wrap_strcpy;
				}
				//printf("%s %d %d\n", tra->rul[order].template ,mapidx, map_size);
			}
			if (strncmp(temp1, "~p", 2) == 0)
			{
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				language_code = line[idx++] - 48;
				if (language_code != 1 && language_code != 2)
				{
					printf("error: perfix's language code should be 1 or 2\n%s\n", line);
					exit(1);
				}
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				tra->rul[order].prefix[language_code - 1] = (char *)realloc(tra->rul[order].prefix[language_code - 1], (strlen(temp1) + 1) * sizeof(char));
				if (temp1[0] != '\"')
				{
					printf("error: perfix should be surround by quote\n%s\n", line);
					exit(1);
				}

				for (i = 0; temp1[i + 1] != '\"'; i++)
				{
					tra->rul[order].prefix[language_code - 1][i] = temp1[i + 1];
				}
				tra->rul[order].prefix[language_code - 1][i] = '\0';
			}
			if (strncmp(temp1, "~f", 2) == 0)
			{
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				language_code = line[idx++] - 48;
				if (language_code != 1 && language_code != 2)
				{
					printf("error: suffix's language code should be 1 or 2\n%s\n", line);
					exit(1);
				}
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				tra->rul[order].suffix[language_code - 1] = (char *)realloc(tra->rul[order].suffix[language_code - 1], (strlen(temp1) + 1) * sizeof(char));
				if (temp1[0] != '\"')
				{
					printf("error: suffix should be surround by quote\n%s\n", line);
					exit(1);
				}

				for (i = 0; temp1[i + 1] != '\"'; i++)
				{
					tra->rul[order].suffix[language_code - 1][i] = temp1[i + 1];
				}
				tra->rul[order].suffix[language_code - 1][i] = '\0';
			}
			if (strncmp(temp1, "~v", 2) == 0)
			{
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				tra->rul[order].rp_capacicty = atoi(temp1);
				tra->rul[order].rp = (REPLACE_PAIR *)realloc(tra->rul[order].rp, tra->rul[order].rp_capacicty * sizeof(REPLACE_PAIR));
			}
			if (strncmp(temp1, "~m", 2) == 0)
			{
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				if (temp1[0] == '0')
				{
					continue;
				}
				idx += 1;

				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				if (temp1[0] != '\"')
				{
					printf("error: replace_source should be surround by quote\n%s\n", line);
					exit(1);
				}
				idx++;
				temp1 = &line[idx];
				for (len = 0; temp1[len] != '\"'; len++)
				{
				}
				tra->rul[order].rp[tra->rul[order].rp_size].raw = (char *)malloc((len + 1) * sizeof(char));
				strncpy(tra->rul[order].rp[tra->rul[order].rp_size].raw, temp1, len);
				tra->rul[order].rp[tra->rul[order].rp_size].raw[len] = '\0';
				idx += len + 1;

				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				if (temp1[0] != ':')
				{
					printf("error: replace pair should be split by colon\n%s\n", line);
					exit(1);
				}
				idx++;

				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				if (temp1[0] != '\"')
				{
					printf("error: replace_destination should be surround by quote\n%s\n", line);
					exit(1);
				}
				idx++;
				temp1 = &line[idx];
				for (len = 0; temp1[len] != '\"'; len++)
				{
				}
				tra->rul[order].rp[tra->rul[order].rp_size].rel = (char *)malloc((len + 1) * sizeof(char));
				strncpy(tra->rul[order].rp[tra->rul[order].rp_size].rel, temp1, len);
				tra->rul[order].rp[tra->rul[order].rp_size].rel[len] = '\0';
				tra->rul[order].rp_size++;
			}
		}
	}
	tra->size = order + 1;
	// for (i = 0; i < tra->size; i++)
	//{
	//	printf("%s, %d, %s, p=%s, s=%s, rp_size=%d\n", tra->rul[i].name, tra->rul[i].status, tra->rul[i].template, tra->rul[i].prefix[0], tra->rul[i].suffix[0], tra->rul[i].rp_size);
	//	for (j = 0; j < tra->rul[i].rp_size; j++)
	//	{
	//		printf("\t%s -> %s\n", tra->rul[i].rp[j].raw, tra->rul[i].rp[j].rel);
	//	}
	// }

	for (i = 0; i < tra->size; i++)
	{
		qsort(tra->rul[i].rp, tra->rul[i].rp_size, sizeof(REPLACE_PAIR), replacecomparefun);
	}
	// for (i = 0; i < tra->size; i++)
	//{
	//	printf("%s, %d, %s, p=%s, s=%s, rp_size=%d\n", tra->rul[i].name, tra->rul[i].status, tra->rul[i].template, tra->rul[i].prefix[0], tra->rul[i].suffix[0], tra->rul[i].rp_size);
	//	for (j = 0; j < tra->rul[i].rp_size; j++)
	//	{
	//		printf("\t%s -> %s\n", tra->rul[i].rp[j].raw, tra->rul[i].rp[j].rel);
	//	}
	// }

	qsort(tra->rul, tra->size, sizeof(TRANSFORMATION_RULES), replacecomparefun);
	// for (i = 0; i < tra->size; i++)
	//{
	//	printf("%s, %d, %s, Mp=%s, Ms=%s, Ep=%s, Es=%s, rp_size=%d %d %d\n", tra->rul[i].name, tra->rul[i].status, tra->rul[i].template, tra->rul[i].prefix[0], tra->rul[i].suffix[0], tra->rul[i].prefix[1], tra->rul[i].suffix[1], tra->rul[i].rp_size, tra->rul[i].scale_size, tra->rul[i].extra_size);
	//	for (j = 0; j < tra->rul[i].rp_size; j++)
	//	{
	//		printf("\t%s -> %s\n", tra->rul[i].rp[j].raw, tra->rul[i].rp[j].rel);
	//	}
	// }

	free(line);
	free(tok);
}
void load_substitution(FILE *frul, SUBSTITUTION *sub)
{
	int FILEEND, capacity_of_line = 0;
	char *line = (char *)malloc(sizeof(char));
	char *temp1, *temp2;
	int i, j, idx, order = -1, colon_idx, space_idx, len, len2, temp_idx;
	int start_idx, end_idx;
	char temp_word[7];

	sub->words = (SUBSTITUTION_WORDS *)malloc(sub->capacity * sizeof(SUBSTITUTION_WORDS));

	for (FILEEND = idx = 0; FILEEND == 0; idx = 0)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, frul);
		if (line[0] != '\0' && line[0] != '#')
		{
			forward_until_not_space_and_tab(line, &idx);
			temp1 = &line[idx];
			if (strncmp(temp1, "~s", 2) == 0)
			{
				if (sub->size >= sub->capacity)
				{
					continue;
				}
				// if (order >= 0)
				//{
				//	sub->words[order].num_templates = temp_idx;
				// }
				temp_idx = 0;
				order++;
				idx += 2;
				sub->words[order].num_templates = 0;
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				for (colon_idx = 0, len = strlen(temp1); temp1[colon_idx] != '\"'; colon_idx++)
				{
					if (colon_idx >= len)
					{
						printf("rule_config format error: %s\n", temp1);
						exit(1);
					}
				}
				start_idx = ++colon_idx;
				for (; temp1[colon_idx] != '\"'; colon_idx++)
				{
					if (colon_idx >= len)
					{
						printf("rule_config format error: %s\n", temp1);
						exit(1);
					}
				}
				end_idx = colon_idx++;
				sub->words[order].raw_word = (char *)malloc((end_idx - start_idx + 1) * sizeof(char));
				strncpy(sub->words[order].raw_word, &temp1[start_idx], end_idx - start_idx);
				sub->words[order].raw_word[end_idx - start_idx] = '\0';
				// printf("%s\n", sub->words[order].raw_word);
				// exit(1);
				forward_until_not_space_and_tab(temp1, &colon_idx);
				if (temp1[colon_idx] != ':')
				{
					printf("rule_config format error: %s\n", temp1);
					exit(1);
				}
				forward_until_not_space_and_tab(temp1, &colon_idx);
				for (colon_idx++; temp1[colon_idx] != '\"'; colon_idx++)
				{
					if (colon_idx >= len)
					{
						printf("rule_config format error: %s\n", temp1);
						exit(1);
					}
				}
				start_idx = ++colon_idx;
				for (colon_idx++; temp1[colon_idx] != '\"'; colon_idx++)
				{
					if (colon_idx >= len)
					{
						printf("rule_config format error: %s\n", temp1);
						exit(1);
					}
				}
				end_idx = colon_idx++;
				sub->words[order].sub_word = (char *)malloc((end_idx - start_idx + 1) * sizeof(char));
				strncpy(sub->words[order].sub_word, &temp1[start_idx], end_idx - start_idx);
				sub->words[order].sub_word[end_idx - start_idx] = '\0';
				// printf("%s\n", sub->words[order].sub_word);
				// exit(1);
				forward_until_not_space_and_tab(temp1, &colon_idx);
				temp1 = &temp1[colon_idx];
				sub->words[order].capacity_templates = atoi(temp1);
				sub->words[order].templates = (TEMPLATE *)malloc(sub->words[order].capacity_templates * sizeof(TEMPLATE));
				// printf("%s %s %s %d %d\n", temp1, sub->words[order].raw_word,
				// sub->words[order].sub_word, colon_idx, space_idx);
				sub->size++;
			}
			else if (strncmp(temp1, "~t", 2) == 0)
			{
				if (temp_idx >= sub->words[order].capacity_templates)
				{
					continue;
				}
				idx += 2;
				forward_until_not_space_and_tab(line, &idx);
				temp1 = &line[idx];
				sub->words[order].templates[temp_idx].str = (char *)malloc((strlen(temp1) + 1) * sizeof(char));
				strcpy(sub->words[order].templates[temp_idx].str, temp1);

				for (i = 0, len2 = strlen(sub->words[order].raw_word), len = strlen(temp1); i < len; i++)
				{
					if (strncmp(&(sub->words[order].templates[temp_idx].str[i]), sub->words[order].raw_word, len2) == 0)
					{
						sub->words[order].templates[temp_idx].replace_idx = i;
					}
				}
				sub->words[order].num_templates++;
				temp_idx++;
			}
			else if (strncmp(temp1, "~e", 2) == 0)
			{
				break;
			}
		}
	}
	/*for (i = 0; i < sub->size; i++)
	{
		printf("%s -> %s\n", sub->words[i].raw_word, sub->words[i].sub_word);
		for (j = 0; j < sub->words[i].num_templates; j++)
		{
			printf("\t%s %d\n", sub->words[i].templates[j].str, sub->words[i].templates[j].replace_idx);
		}
	}*/
	qsort(sub->words, sub->size, sizeof(SUBSTITUTION_WORDS), subcomparefun);
	/*for (i = 0; i < sub->size; i++)
	{
		printf("%s -> %s\n", sub->words[i].raw_word, sub->words[i].sub_word);
		for (j = 0; j < sub->words[i].num_templates; j++)
		{
			printf("\t%s\n", sub->words[i].templates[j]);
		}
	}*/
	sub->list.capacity = sub->size;
	sub->list.word = (char **)malloc(sub->list.capacity * sizeof(char *));
	sub->list.statr_idx = (int *)malloc(sub->list.capacity * sizeof(int));
	if (sub->size > 0)
	{
		sub->list.word[0] = (char *)malloc((strlen(sub->words[0].raw_word) + 1) * sizeof(char));
		strcpy(sub->list.word[0], sub->words[0].raw_word);
		sub->list.statr_idx[0] = 0;
		sub->list.size = 1;
	}
	for (i = 1, temp_idx = 0; i < sub->size; i++, temp_idx = 0)
	{
		read_a_utf8_word(sub->words[i].raw_word, temp_word, &temp_idx);
		if (strncmp(sub->words[i].raw_word, sub->words[i - 1].raw_word, temp_idx) != 0)
		// if (sub->words[i].raw_word[0] != sub->words[i - 1].raw_word[0])
		{
			sub->list.word[sub->list.size] = (char *)malloc((strlen(sub->words[i].raw_word) + 1) * sizeof(char));
			strcpy(sub->list.word[sub->list.size], sub->words[i].raw_word);
			sub->list.statr_idx[sub->list.size] = i;
			sub->list.size++;
		}
	}
	/*for (i = 0; i < sub->list.size; i++)
	{
		printf("%s %d\n",sub->list.word[i],sub->list.statr_idx[i]);
	}*/

	free(line);
}
void substitute(TEXT *text_in, TEXT *text_tmp, SUBSTITUTION *sub)
{
	int i = 0, j = 0, k = 0, ret = 0, start = 0, end = 0;
	char word[7] = "\0";
	int idx_sent = 0, idx_comp = 0, len_sent = 0, len_sub_word = 0;

	text_tmp->num_of_sentence = text_in->num_of_sentence;
	text_tmp->sentence = (char **)malloc(text_tmp->num_of_sentence * sizeof(char *));

	for (i = 0; i < text_in->num_of_sentence; i++)
	{
		text_tmp->sentence[i] = (char *)malloc((strlen(text_in->sentence[i]) + 1) * sizeof(char));
		strcpy(text_tmp->sentence[i], text_in->sentence[i]);

		for (idx_sent = 0, len_sent = strlen(text_tmp->sentence[i]); idx_sent < len_sent;)
		{
			ret = bin_substitution_search(&text_tmp->sentence[i][idx_sent], &(sub->list));
			if (ret >= 0)
			{
				// printf("%s\n", &text_tmp->sentence[i][idx_sent]);
				start = sub->list.statr_idx[ret];
				if (ret == sub->list.size - 1)
				{
					end = sub->size;
				}
				else
				{
					end = sub->list.statr_idx[ret + 1];
				}
				// printf("%s %d %d\n", sub->list.word[ret], start, end);
				for (j = start; j < end; j++)
				{
					for (k = 0; k < sub->words[j].num_templates; k++)
					{
						idx_comp = idx_sent;
						// printf("%s %s\n", sub->words[j].templates[k].str, &text_tmp->sentence[i][idx_comp]);
						if (compare_template(&(sub->words[j].templates[k]), text_tmp->sentence[i], idx_comp) == 1)
						{
							// printf("%s\n", text_tmp->sentence[i]);
							substituting(&(sub->words[j]), &(text_tmp->sentence[i]), idx_comp);
							len_sent = strlen(text_tmp->sentence[i]);
							// printf("%s\n", text_tmp->sentence[i]);
						}
					}
				}
			}

			read_a_utf8_word(text_tmp->sentence[i], word, &idx_sent);
			if (word[0] == '\0')
			{
				break;
			}
		}

		// ret = bin_substitution_search();

		/*if (text_tmp->sentence[i][0] != '\0')
		{
			for (j = 0; j < sub->size; j++)
			{
				for (idx_sent = 0, len_sent = strlen(text_tmp->sentence[i]),len_sub_word = strlen(sub->words[j].raw_word);idx_sent < len_sent; idx_sent++)
				{
					 //printf("%s %s %d\n", text_tmp->sentence[i], sub->words[j].raw_word,len_sub_word);
					if (strncmp(&(text_tmp->sentence[i][idx_sent]),sub->words[j].raw_word, len_sub_word) == 0)
					{
						 //printf("%s %d ", sub->words[j].raw_word, sub->words[j].num_templates);
						for (k = 0; k < sub->words[j].num_templates; k++)
						{
							 //printf("%s\n",sub->words[j].templates[k].str);
							idx_comp = idx_sent;
							if (compare_template(&(sub->words[j].templates[k]),text_tmp->sentence[i], idx_comp) == 1)
							{
								 //printf("%s\n", text_tmp->sentence[i]);
								substituting(&(sub->words[j]), &(text_tmp->sentence[i]),idx_comp);
								 //printf("%s\n", text_tmp->sentence[i]);
							}
						}
					}
				}
			}
		}*/
	}
}
int compare_template(TEMPLATE *template, char *sentence, int idx)
{
	int i, ret, idx_temp, len_go_back, len_template;
	char word[7], word_dummy[7];
	int left_null, idx_dummy;

	for (idx_temp = len_go_back = 0; idx_temp < template->replace_idx; len_go_back++)
	{
		if (isctrl_char(&(template->str[idx_temp])) == 1)
		{
			idx_temp += 5;
		}
		else
		{
			read_a_utf8_word(template->str, word, &idx_temp);
			// printf("idx_temp = %d ", idx_temp);
		}
	}
	// printf("%s, len_go_back = %d, template->replace_idx = %d\n", template->str, len_go_back, template->replace_idx);
	for (i = left_null = 0; i < len_go_back; i++)
	{
		if (Retreat_a_utf8_word(sentence, &idx) == 0)
		{
			left_null++;
		}
	}
	// printf("%s %d\n", template->str, strlen(template->str));

	for (idx_temp = 0, len_template = strlen(template->str); idx_temp < len_template;)
	{
		if (left_null > 0)
		{
			word[0] = 1;
			word[1] = '\0';
			left_null--;
		}
		else
		{
			ret = read_a_utf8_word(sentence, word, &idx);
			if (ret == 1)
			{
				word[0] = 1;
				word[1] = '\0';
			}
		}
		// printf("word = %s\n", word);
		if (strncmp(&(template->str[idx_temp]), _NAN_, 5) == 0)
		{
			idx_temp += 5;
			// read_a_utf8_word(sentence, word, &idx);
			if (isNumber(word) == 1)
			{
				return 0;
			}
		}
		else if (strncmp(&(template->str[idx_temp]), _NAE_, 5) == 0)
		{
			idx_temp += 5;
			// read_a_utf8_word(sentence, word, &idx);
			if (isEnglish(word) == 1)
			{
				return 0;
			}
		}
		else if (strncmp(&(template->str[idx_temp]), _NAM_, 5) == 0)
		{
			idx_temp += 5;
			// read_a_utf8_word(sentence, word, &idx);
			if (isCJK_words(word) == 1)
			{
				return 0;
			}
		}
		else if (strncmp(&(template->str[idx_temp]), _IAN_, 5) == 0)
		{
			idx_temp += 5;
			// read_a_utf8_word(sentence, word, &idx);
			if (isNumber(word) == 0)
			{
				return 0;
			}
		}
		else if (strncmp(&(template->str[idx_temp]), _IAE_, 5) == 0)
		{
			idx_temp += 5;
			// read_a_utf8_word(sentence, word, &idx);
			if (isEnglish(word) == 0)
			{
				return 0;
			}
		}
		else if (strncmp(&(template->str[idx_temp]), _IAM_, 5) == 0)
		{
			idx_temp += 5;
			// read_a_utf8_word(sentence, word, &idx);
			if (isCJK_words(word) == 0)
			{
				return 0;
			}
		}
		else
		{
			// ret = read_a_utf8_word(sentence, word, &idx);
			if (strncmp(&(template->str[idx_temp]), word, strlen(word)) != 0)
			{
				// printf("1 %s %s\n", &(template->str[idx_temp]), word);
				return 0;
			}
			// printf("2 %s %s\n", &(template->str[idx_temp]), word);
			idx_dummy = idx_temp;
			ret = read_a_utf8_word(template->str, word_dummy, &idx_dummy);
			if (ret == 1)
			{
				idx_temp++;
			}
			else
			{
				idx_temp += strlen(word_dummy);
			}
			// printf("%s word_dummy=%s\n", &(template->str[idx_temp]), word_dummy);
			// idx_temp += strlen(word);
		}
	}
	// printf("%s\n", sentence);
	// printf("%s len_go_back = %d, template->replace_idx = %d\n", template->str,len_go_back, template->replace_idx);
	return 1;
}
int isctrl_char(char *str)
{
	int i = 0;

	for (i = 0; i < 6; i++)
	{
		if (strncmp(str, crtl_char[i], strlen(crtl_char[i])) == 0)
		{
			return 1;
		}
	}

	return 0;
}
void substituting(SUBSTITUTION_WORDS *sub_word, char **sentence, int idx)
{
	char *line = (char *)malloc((strlen(*sentence) + strlen(sub_word->sub_word) + 1) * sizeof(char));
	char word[7], *tmp;

	strncpy(line, *sentence, idx);
	line[idx] = '\0';
	strcat(line, sub_word->sub_word);
	idx += strlen(sub_word->raw_word);
	strcat(line, &((*sentence)[idx]));

	tmp = *sentence;
	*sentence = line;

	free(tmp);
}
void destroy_rules(RULES *rul)
{
	destroy_substitution(&(rul->sub));
	destroy_transformation(&(rul->tra));
}
void destroy_transformation(TRANSFORMATION *tra)
{
	int i, j;

	for (i = 0; i < tra->size; i++)
	{
		for (j = 0; j < tra->rul[i].rp_size; j++)
		{
			free(tra->rul[i].rp[j].raw);
			free(tra->rul[i].rp[j].rel);
		}
		free(tra->rul[i].name);
		free(tra->rul[i].prefix[0]);
		free(tra->rul[i].prefix[1]);
		free(tra->rul[i].prefix);
		free(tra->rul[i].rp);
		free(tra->rul[i].suffix[0]);
		free(tra->rul[i].suffix[1]);
		free(tra->rul[i].suffix);
		free(tra->rul[i].template);
	}
	free(tra->rul);
}
void destroy_substitution(SUBSTITUTION *sub)
{
	int i, j;

	for (i = 0; i < sub->size; i++)
	{
		for (j = 0; j < sub->words[i].num_templates; j++)
		{
			free(sub->words[i].templates[j].str);
		}
		free(sub->words[i].raw_word);
		free(sub->words[i].sub_word);
		free(sub->words[i].templates);
	}
	free(sub->words);
	for (i = 0; i < sub->list.size; i++)
	{
		free(sub->list.word[i]);
	}
	free(sub->list.word);
	free(sub->list.statr_idx);
}
void destroy_flags(FLAGS *flags)
{
	int i;

	for (i = 0; i < flags->size; i++)
	{
		free(flags->token[i].rules);
	}
	free(flags->token);
}
int transformationcomparefun(const void *a, const void *b)
{
	const char *pa = ((TRANSFORMATION_RULES *)a)->name;
	const char *pb = ((TRANSFORMATION_RULES *)b)->name;
	return strcmp(pa, pb);
}
int replacecomparefun(const void *a, const void *b)
{
	const char *pa = ((REPLACE_PAIR *)a)->raw;
	const char *pb = ((REPLACE_PAIR *)b)->raw;
	return strcmp(pa, pb);
}
int subcomparefun(const void *a, const void *b)
{
	const char *pa = ((SUBSTITUTION_WORDS *)a)->raw_word;
	const char *pb = ((SUBSTITUTION_WORDS *)b)->raw_word;
	return strcmp(pa, pb);
}
int flagscomparefun(const void *a, const void *b)
{
	const char *pa = ((FLAG_TOKEN *)a)->rules;
	const char *pb = ((FLAG_TOKEN *)b)->rules;
	return strcmp(pa, pb);
}
int stringcomparefun(const void *a, const void *b)
{
	const char *pa = (*(char **)a);
	const char *pb = (*(char **)b);
	return strcmp(pa, pb);
}
int stringlengthcomparefun(const void *a, const void *b)
{
	int alen = strlen((*(char **)a));
	int blen = strlen((*(char **)b));
	if (alen > blen)
	{
		return 1;
	}
	else if (alen == blen)
	{
		return 0;
	}
	return -1;
}
int bin_replace_word_search(char *rel_word, TRANSFORMATION_RULES *trel)
{
	int tmp, low = 0, up = trel->rp_size - 1, middle;

	while (1)
	{
		middle = (low + up) * 0.5;
		if (strncmp(rel_word, trel->rp[middle].raw, strlen(trel->rp[middle].raw)) > 0)
		{
			low = middle + 1;
		}
		else if (strncmp(rel_word, trel->rp[middle].raw, strlen(trel->rp[middle].raw)) == 0)
		{
			for (tmp = middle; tmp < trel->rp_size; tmp++)
			{
				if (strncmp(rel_word, trel->rp[tmp].raw, strlen(trel->rp[tmp].raw)) == 0 && strlen(trel->rp[tmp].raw) >= strlen(trel->rp[middle].raw))
				{
					middle = tmp;
					continue;
				}
				break;
			}
			return middle;
		}
		else if (strncmp(rel_word, trel->rp[middle].raw, strlen(trel->rp[middle].raw)) < 0)
		{
			up = middle - 1;
		}
		if ((up == low && up == middle) || up < low)
		{
			return -1;
		}
	}
}
int bin_transform_rule_search(char *rul_name, TRANSFORMATION *tra)
{
	int i, low = 0, up = tra->size - 1, middle;

	while (1)
	{
		middle = (low + up) * 0.5;
		if (strcmp(rul_name, tra->rul[middle].name) > 0)
		{
			low = middle + 1;
		}
		else if (strcmp(rul_name, tra->rul[middle].name) == 0)
		{
			return middle;
		}
		else if (strcmp(rul_name, tra->rul[middle].name) < 0)
		{
			up = middle - 1;
		}
		if ((up == low && up == middle) || up < low)
		{
			return -1;
		}
	}
}
int bin_substitution_search(char *sentence, SUBSTITUTION_WORDS_LIST *list)
{
	int i = 0, low = 0, up = list->size - 1, middle = 0;
	int temp_idx = 0;
	char word[7] = "\0";

	while (1)
	{
		middle = (low + up) * 0.5;
		temp_idx = 0;
		read_a_utf8_word(list->word[middle], word, &temp_idx);
		if (strncmp(sentence, list->word[middle], temp_idx) > 0)
		{
			low = middle + 1;
		}
		else if (strncmp(sentence, list->word[middle], temp_idx) == 0)
		{
			return middle;
		}
		else if (strncmp(sentence, list->word[middle], temp_idx) < 0)
		{
			up = middle - 1;
		}
		if ((up == low && up == middle) || up < low)
		{
			return -1;
		}
	}
}
int bin_flags_search(char *rule, FLAGS *flags)
{
	int i, low = 0, up = flags->size - 1, middle;

	while (1)
	{
		middle = (low + up) * 0.5;
		if (strcmp(rule, flags->token[middle].rules) > 0)
		{
			low = middle + 1;
		}
		else if (strcmp(rule, flags->token[middle].rules) == 0)
		{
			return middle;
		}
		else if (strcmp(rule, flags->token[middle].rules) < 0)
		{
			up = middle - 1;
		}
		if ((up == low && up == middle) || up < low)
		{
			return -1;
		}
	}
}
int bin_string_search_len_match(char *sentence, char **set, int set_size)
{
	int i, low = 0, up = set_size - 1, middle;

	while (1)
	{
		middle = (low + up) * 0.5;
		// printf("%s %d %d %d\n", set[middle], low, up, middle);
		if (strncmp(sentence, set[middle], strlen(set[middle])) > 0)
		{
			low = middle + 1;
		}
		else if (strncmp(sentence, set[middle], strlen(set[middle])) == 0)
		{
			return middle;
		}
		else if (strncmp(sentence, set[middle], strlen(set[middle])) < 0)
		{
			up = middle - 1;
		}
		if ((up == low && up == middle) || up < low)
		{
			return -1;
		}
	}
}
int check_flags(char *rule, FLAGS *flags)
{
	int ret;

	ret = bin_flags_search(rule, flags);
	if (ret != -1)
	{
		if (flags->token[ret].on == 1)
		{
			return 1;
		}
	}

	return 0;
}
void MMTDSF(char *num_in, char *MMT, int language_code)
{
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char word[7];
	int idx, dao_flag = -1;

	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			dao_flag = 1;
			break;
		}
		else if (strcmp(word, ch_dao) == 0)
		{
			dao_flag = 0;
			break;
		}
		else
		{
			strcat(temp, word);
		}
	}
	CSTSFW(temp, MMT, language_code);
	if (dao_flag > -1)
	{
		if (dao_flag == 0)
		{
			strcat(MMT, word);
		}
		else if (dao_flag == 1)
		{
			if (language_code == 1)
			{
				strcat(MMT, ch_dao);
			}
			else
			{
				strcat(MMT, "to ");
			}
		}
		// for (temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
		//{
		//	if (isNumber(word) == 1 || isDot(word) == 1)
		//	{
		//		strcat(temp, word);
		//	}
		// }
		strcpy(temp, &num_in[idx]);
		CSTSFW(temp, MMT, language_code);
	}
	free(temp);
}
void CSTSFW(char *num_in, char *CST, int language_code)
{
	char *N_country_name = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *country_name = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *numerals = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *N_numerals = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char currency_symbol[7] = "";
	char word[7];
	int i, idx, bidx, csi = -1, ret, b_flag;

	for (ret = 0, idx = 0, b_flag = 0; ret == 0 && b_flag == 0;)
	{
		for (i = 0; i < 22; i++)
		{
			if (strncmp(&num_in[idx], currency_symbols[i], strlen(currency_symbols[i])) == 0)
			{
				strcpy(currency_symbol, currency_symbols[i]);
				b_flag = 1;
				break;
			}
		}
		ret = read_a_utf8_word(num_in, word, &idx);
	}
	for (idx = 0, country_name[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isEnglish(word) == 1)
		{
			strcat(country_name, word);
		}
	}
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			strcpy(numerals, &num_in[idx]);
			for (bidx = strlen(num_in); 1;)
			{
				Retreat_a_utf8_word(num_in, &bidx);
				read_a_utf8_word(num_in, word, &bidx);
				if (isNumber(word) == 1)
				{
					break;
				}
				Retreat_a_utf8_word(num_in, &bidx);
			}
			numerals[bidx - idx] = '\0';
			break;
		}
	}
	normalize_english_uppercase(country_name, N_country_name);
	normalize_number(numerals, N_numerals);
	// printf("%s %s %s %s %d\n", N_country_name, currency_symbol, numerals, N_numerals, bidx - idx);
	for (i = 0; i < 18; i++)
	{
		if (strcmp(currency_symbol, currsym2spokenform[i][0]) == 0)
		{
			csi = i;
			break;
		}
	}

	if (language_code == 1)
	{
		if (N_country_name[0] != '\0' && currency_symbol[0] == '\0')
		{
			N2SWND(num_in, CST, language_code);
		}
		else if (N_country_name[0] != '\0')
		{
			ret = country_name_idx(N_country_name);
			if (ret >= 0)
			{
				N2SWND(numerals, CST, language_code);
				strcat(CST, country_abbr[ret][1]);
			}
			else
			{
				strcat(CST, N_country_name);
				N2SWND(numerals, CST, language_code);
			}
		}
		else
		{
			N2SWND(numerals, CST, language_code);
			if (csi >= 0)
			{
				strcat(CST, currsym2spokenform[csi][2]);
			}
		}
	}
	else
	{
		N2SWND(numerals, CST, language_code);
		if (N_country_name[0] != '\0')
		{
			strcat(CST, N_country_name);
			if (csi >= 0)
			{
				strcat(CST, " ");
				strcat(CST, currsym2spokenform[csi][1]);
			}
			else if (strcmp(currency_symbol, "") != 0)
			{
				if (strcmp(N_numerals, "1") == 0 || strcmp(N_numerals, "0") == 0)
				{
					strcat(CST, " dollar");
				}
				else
				{
					strcat(CST, " dollars");
				}
			}
		}
		else
		{
			if (csi >= 0)
			{
				if (strcmp(N_numerals, "1") == 0 || strcmp(N_numerals, "0") == 0)
				{
					strcat(CST, currsym2spokenform[csi][1]);
				}
				else
				{
					pluralize(currsym2spokenform[csi][1], &CST[strlen(CST)]);
				}
			}
		}
	}

	free(N_country_name);
	free(country_name);
	free(N_numerals);
	free(numerals);
}
void YMTYMT(char *num_in, char *YMT, int language_code)
{
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char word[7];
	int idx, cat_flag = 0, YMT_idx, mark_num = 0;

	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDot(word) == 0 && isSlash(word) == 0 && isDash(word) == 0 && isNumber(word) == 0 && isspaces(word) == 0)
		{
			break;
		}
		if (isDash(word) == 1 || isSlash(word) == 1 || isDot(word) == 1)
		{
			mark_num++;
			if (mark_num == 2)
			{
				break;
			}
		}
		strcat(temp, word);
	}
	YMTSFW(temp, &YMT[strlen(YMT)], language_code);
	// printf("%s\n", temp);
	if (isTilde(word) == 1 || isDash(word) == 1)
	{
		strcat(YMT, ch_dao);
		cat_flag = 1;
	}
	else if (strcmp(word, Mandarin_day) == 0 || strcmp(word, Mandarin_number) == 0)
	{
		YMT_idx = strlen(YMT);
		Retreat_a_utf8_word(YMT, &YMT_idx);
		strcpy(&YMT[YMT_idx], word);
	}
	else if (isCJK_words(word) == 1)
	{
		strcat(YMT, word);
		cat_flag = 1;
	}
	if (cat_flag == 1)
	{
		for (temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isDot(word) == 0 && isSlash(word) == 0 && isDash(word) == 0 && isNumber(word) == 0 && isspaces(word) == 0)
			{
				break;
			}
			strcat(temp, word);
		}
		YMTSFW(temp, &YMT[strlen(YMT)], language_code);

		if (strcmp(word, Mandarin_day) == 0 || strcmp(word, Mandarin_number) == 0)
		{
			YMT_idx = strlen(YMT);
			Retreat_a_utf8_word(YMT, &YMT_idx);
			strcpy(&YMT[YMT_idx], word);
		}
	}
	free(temp);
}
void DMYTSF(char *num_in, char *DMY, int language_code)
{
	int i, idx, i_temp, size;
	char word[7];
	char **temp = (char **)malloc(3 * sizeof(char *));
	char *nor_num_in = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	temp[0] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[1] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[2] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	normalize_date(num_in, nor_num_in);

	temp[0][0] = temp[1][0] = temp[2][0] = '\0';
	for (idx = size = 0; read_a_utf8_word(nor_num_in, word, &idx) == 0;)
	{
		if (word[0] == '.' || word[0] == '/' || word[0] == '-')
		{
			size++;
		}
		else
		{
			strcat(temp[size], word);
		}
	}

	// printf("%s %s %s\n", temp[0], temp[1], temp[2]);
	if (size == 2) // DMY
	{
		STFNVI(temp[2], &DMY[strlen(DMY)]);
		strcat(DMY, Mandarin_year);
		DPTSFW(temp[1], &DMY[strlen(DMY)], 1);
		strcat(DMY, Mandarin_month);
		DPTSFW(temp[0], &DMY[strlen(DMY)], 1);
		strcat(DMY, retdaynum());
	}
	else if (size == 1) // MY
	{
		STFNVI(temp[1], &DMY[strlen(DMY)]);
		strcat(DMY, Mandarin_year);
		DPTSFW(temp[0], &DMY[strlen(DMY)], 1);
		strcat(DMY, Mandarin_month);
	}

	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	free(nor_num_in);
}
void DTDYMD(char *num_in, char *DTD, int language_code)
{
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char word[7];
	int idx, cat_flag = 0, DTD_idx, num_dash = 0, num_dot = 0, num_slash = 0;
	char *prefix = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0, prefix[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		strcat(prefix, word);
	}

	for (temp[0] = '\0', DTD[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1)
		{
			num_dash++;
		}
		else if (isDot(word) == 1)
		{
			num_dot++;
		}
		else if (isSlash(word) == 1)
		{
			num_slash++;
		}
		if (isTilde(word) == 1 || num_dash == 3)
		{
			break;
		}
		else if (num_dash == 1 && (num_dot == 2 || num_slash == 2))
		{
			break;
		}
		else if (isCJK_words(word) == 1 && (num_dot == 2 || num_slash == 2 || num_dash == 2))
		{
			break;
		}
		else if (isL_Brackets(word) == 1)
		{
			break;
		}
		strcat(temp, word);
	}
	// printf("%s\n", temp);
	strcat(DTD, prefix);
	NWDSFW(temp, &DTD[strlen(DTD)]);
	if (isTilde(word) == 1 || isDash(word) == 1)
	{
		strcat(DTD, ch_dao);
		cat_flag = 1;
	}
	else if (strcmp(word, Mandarin_day) == 0 || strcmp(word, Mandarin_number) == 0)
	{
		DTD_idx = strlen(DTD);
		Retreat_a_utf8_word(DTD, &DTD_idx);
		strcpy(&DTD[DTD_idx], word);
	}
	else if (isL_Brackets(word) == 1)
	{

		Retreat_a_utf8_word(num_in, &idx);
		add_day_suffix(&num_in[idx], DTD);
	}
	else if (isCJK_words(word) == 1)
	{
		strcat(DTD, word);
		cat_flag = 1;
	}
	if (cat_flag == 1)
	{
		for (temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isDot(word) == 0 && isSlash(word) == 0 && isDash(word) == 0 && isNumber(word) == 0 && isspaces(word) == 0)
			{
				break;
			}
			strcat(temp, word);
		}
		NWDSFW(temp, &DTD[strlen(DTD)]);

		if (strcmp(word, Mandarin_day) == 0 || strcmp(word, Mandarin_number) == 0)
		{
			DTD_idx = strlen(DTD);
			Retreat_a_utf8_word(DTD, &DTD_idx);
			strcpy(&DTD[DTD_idx], word);
		}
	}
	free(temp);
	free(prefix);
}
void DSPFWW(char *num_in, char *DSF, int language_code)
{
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char word[7];
	int idx, cat_flag = 0;

	for (idx = 0, DSF[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			strcat(DSF, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 1 || isSlash(word) == 1)
				{
					strcat(temp, word);
				}
				else
				{
					break;
				}
			}
			MDTSFW(temp, &DSF[strlen(DSF)]);
			// printf("%s\n", temp);
			strcat(DSF, word);
		}
	}
	free(temp);
}
void YMTSFW(char *num_in, char *YMT, int language_code)
{
	int i, idx, i_temp, size, nidx;
	char word[7];
	char **temp = (char **)malloc(3 * sizeof(char *));
	char *nor_num_in = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (nidx = 0; read_a_utf8_word(num_in, word, &nidx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &nidx);
			break;
		}
		strcat(YMT, word);
	}

	temp[0] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[1] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[2] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	normalize_date(&num_in[nidx], nor_num_in);
	// printf("%s %s\n", num_in, nor_num_in);
	// fflush(stdout);
	temp[0][0] = temp[1][0] = temp[2][0] = '\0';
	for (idx = size = 0; read_a_utf8_word(nor_num_in, word, &idx) == 0;)
	{
		if (word[0] == '.' || word[0] == '/' || word[0] == '-' || word[0] == '~')
		{
			size++;
		}
		else
		{
			strcat(temp[size], word);
		}
	}
	// printf("%s %s %s\n", temp[0], temp[1], temp[2]);
	STFNVI(temp[0], &YMT[strlen(YMT)]);
	strcat(YMT, Mandarin_year);
	DPTSFW(temp[1], &YMT[strlen(YMT)], 1);
	strcat(YMT, Mandarin_month);
	if (strlen(temp[2]) > 0)
	{
		strcat(YMT, ch_dao);
		DPTSFW(temp[2], &YMT[strlen(YMT)], 1);
		strcat(YMT, Mandarin_month);
	}

	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	free(nor_num_in);
}
void NWDSFW(char *num_in, char *DPSPW)
{
	int i, idx, i_temp, size;
	char word[7];
	char **temp = (char **)malloc(3 * sizeof(char *));
	char *nor_num_in = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	temp[0] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[1] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[2] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	normalize_date(num_in, nor_num_in);

	temp[0][0] = temp[1][0] = temp[2][0] = '\0';
	for (idx = size = 0; read_a_utf8_word(nor_num_in, word, &idx) == 0;)
	{
		if (word[0] == '.' || word[0] == '/' || word[0] == '-')
		{
			size++;
		}
		else
		{
			strcat(temp[size], word);
		}
	}
	if (size == 2)
	{
		// printf("%s %s %s\n", temp[0], temp[1], temp[2]);
		if (utf8_word_length(temp[0]) == 4)
		{
			STFNVI(temp[0], &DPSPW[strlen(DPSPW)]);
		}
		else
		{
			DPTSFW(temp[0], &DPSPW[strlen(DPSPW)], 1);
		}
		strcat(DPSPW, Mandarin_year);
		DPTSFW(temp[1], &DPSPW[strlen(DPSPW)], 1);
		strcat(DPSPW, Mandarin_month);
		DPTSFW(temp[2], &DPSPW[strlen(DPSPW)], 1);
		strcat(DPSPW, retdaynum());
	}
	else if (size == 1)
	{
		DPTSFW(temp[0], &DPSPW[strlen(DPSPW)], 1);
		strcat(DPSPW, Mandarin_month);
		DPTSFW(temp[1], &DPSPW[strlen(DPSPW)], 1);
		strcat(DPSPW, retdaynum());
	}
	else if (size == 0)
	{
		DPTSFW(temp[0], &DPSPW[strlen(DPSPW)], 1);
		strcat(DPSPW, retdaynum());
	}

	/*for (idx = 0; nor_num_in[idx] != '.' && nor_num_in[idx] != '/' && nor_num_in[idx] != '-'; idx++)
	{
		temp[idx] = nor_num_in[idx];
	}
	temp[idx] = '\0';
	if (idx == 1)
	{
		NTNSFW(temp, DPSPW, 0);
	}
	else if (idx < 4)
	{
		NTNSFW(temp, DPSPW, 1);
	}
	else //more than four digits
	{
		NTISFW(temp, DPSPW, 0);
	}

	strcat(DPSPW, Mandarin_year);
	idx++;
	if (nor_num_in[idx] == '0')
	{
		idx++;
	}
	for (i = 0; nor_num_in[i + idx] != '.' && nor_num_in[i + idx] != '/' && nor_num_in[i + idx] != '-'; i++)
	{
		temp[i] = nor_num_in[i + idx];
	}
	temp[i] = '\0';
	if (i == 1)
	{
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 0);
	}
	else
	{
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 1);
	}

	strcat(DPSPW, Mandarin_month);
	idx += i + 1;
	if (nor_num_in[idx] == '0')
	{
		idx++;
	}

	for (i = 0; nor_num_in[i + idx] != '\0'; i++)
	{
		temp[i] = nor_num_in[i + idx];
	}
	temp[i] = '\0';
	if (i == 1)
	{
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 0);
	}
	else
	{
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 1);
	}
	if (cat_day == 1)
	{
		strcat(DPSPW, Mandarin_day);
	}*/

	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	free(nor_num_in);
}
void FRACSFW(char *num_in, char *DPSPW, int language_code)
{
	int i, idx, idex_temp;
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *temp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *nor_num_in = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	normalize_date(num_in, nor_num_in);

	for (idx = 0; nor_num_in[idx] == '0'; idx++)
	{
		continue;
	}
	for (idex_temp = 0; nor_num_in[idx] != '/'; idx++)
	{
		temp[idex_temp++] = nor_num_in[idx];
	}
	temp[idex_temp] = '\0';

	for (idx++; nor_num_in[idx] == '0'; idx++)
	{
		continue;
	}
	for (i = 0; nor_num_in[i + idx] != '\0'; i++)
	{
		temp2[i] = nor_num_in[i + idx];
	}
	temp2[i] = '\0';
	// if (i == 1)
	//{
	//	NTNSFW(temp2, DPSPW, 0);
	// }
	// else
	//{
	//	NTNSFW(temp2, DPSPW, 1);
	// }
	DPTSFW(temp2, DPSPW, 1);
	strcat(DPSPW, fraction);

	// if (idex_temp == 1)
	//{
	//	NTNSFW(temp, &DPSPW[strlen(DPSPW)], 0);
	// }
	// else
	//{
	//	NTNSFW(temp, &DPSPW[strlen(DPSPW)], 1);
	// }
	DPTSFW(temp, &DPSPW[strlen(DPSPW)], 1);

	free(temp);
	free(temp2);
	free(nor_num_in);
}
void PTSFW(char *num_in, char *DPSPW, int language_code)
{
	int i, idx, i_temp;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isColon(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			strncpy(temp, num_in, idx);
			temp[idx] = '\0';
			break;
		}
	}

	if (idx == 1)
	{
		NTNSFW(temp, DPSPW, 0);
	}
	else
	{
		NTNSFW(temp, DPSPW, 1);
	}
	strcat(DPSPW, proportion);
	// memset(temp, 0, sizeof(temp));
	memset(temp, 0, (strlen(num_in) + 1) * sizeof(char));

	for (i = 0, read_a_utf8_word(num_in, word, &idx); read_a_utf8_word(num_in, word, &idx) == 0; i++)
	{
		if (isColon(word) == 1 || word[0] == '\0')
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		strcat(temp, word);
	}

	if (i == 1)
	{
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 0);
	}
	else
	{
		NTNSFW(temp, &DPSPW[strlen(DPSPW)], 1);
	}
	// memset(temp, 0, sizeof(temp));
	memset(temp, 0, (strlen(num_in) + 1) * sizeof(char));

	while (isColon(word)) // 11:12:2
	{
		strcat(DPSPW, proportion);
		for (i = 0, read_a_utf8_word(num_in, word, &idx); read_a_utf8_word(num_in, word, &idx) == 0; i++)
		{
			if (isColon(word) == 1 || word[0] == '\0')
			{
				Retreat_a_utf8_word(num_in, &idx);
				break;
			}
			strcat(temp, word);
		}

		if (i == 1)
		{
			NTNSFW(temp, &DPSPW[strlen(DPSPW)], 0);
		}
		else
		{
			NTNSFW(temp, &DPSPW[strlen(DPSPW)], 1);
		}
		// memset(temp, 0, sizeof(temp));
		memset(temp, 0, (strlen(num_in) + 1) * sizeof(char));
	}

	free(temp);
}
void SDPTSFW(char *num_in, char *DPSPW)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) != 1)
		{
			break;
		}
	}
	Retreat_a_utf8_word(num_in, &idx);
	strncpy(temp, num_in, idx);
	temp[idx] = '\0';

	if (idx == 1)
	{
		NTNSFW(temp, DPSPW, 0);
	}
	else
	{
		NTNSFW(temp, DPSPW, 1);
	}

	free(temp);
}
void replacement(char **line, int *start_idx, char *rel_raw, char *rel_des)
{
	char *temp = (char *)malloc((strlen(*line) + 1) * sizeof(char));

	strcpy(temp, &((*line)[*start_idx + strlen(rel_raw)]));

	(*line) = (char *)realloc((*line), (strlen((*line)) + strlen(rel_des) - strlen(rel_raw) + 1) * sizeof(char));
	(*line)[*start_idx] = '\0';
	strcat((*line), rel_des);
	strcat((*line), temp);
	(*start_idx) += strlen(rel_des);

	free(temp);
}
void NESWND(char *num_in, char *DPSPW, int language_code)
{
	int i, idx, DP_idx;
	char word[7], DP_check[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			DP_idx = strlen(DPSPW);
			if (DP_idx > 0)
			{
				Retreat_a_utf8_word(DPSPW, &DP_idx);
				read_a_utf8_word(DPSPW, DP_check, &DP_idx);
				if (isspaces(DP_check) == 0 && isDash(DP_check) == 0)
				{
					strcat(DPSPW, " ");
				}
			}
			DPESFW(temp, &(DPSPW[strlen(DPSPW)]));
			if (isDash(word) == 1)
			{
				DPSPW[strlen(DPSPW) - 1] = '\0';
			}
			strcat(DPSPW, word);
		}
	}

	free(temp);
}
void N2SSTF(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			STFNVI(temp, &(DPSPW[strlen(DPSPW)]));
			strcat(DPSPW, word);
		}
	}

	free(temp);
}
void CH_N2SWND(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			DPTSFW(temp, &(DPSPW[strlen(DPSPW)]), 1);

			strcat(DPSPW, word);
		}
	}

	free(temp);
}
void MS2SFW(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7], last[7], next[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isPlus(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			read_a_utf8_word(num_in, next, &idx);
			if (next[0] != '\0')
			{
				Retreat_a_utf8_word(num_in, &idx);
			}
			insert_string(DPSPW, last, next, "plus");
		}
		strcpy(last, word);
	}

	free(temp);
}
void DCSOIN(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	// printf("DCSOIN %s\n", num_in);
	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDot(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcat(DPSPW, CH_point);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			NTISFW(temp, &(DPSPW[strlen(DPSPW)]), 0);

			if (idx < strlen(num_in))
			{
				Retreat_a_utf8_word(num_in, &idx);
				strcat(DPSPW, &num_in[idx]);
			}
			break;
		}
	}

	free(temp);
}
void CONAFF(char *num_in, char *ordinal, int language_code)
{
	int idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			strcat(temp, word);
		}
		else
		{
			continue;
		}
	}
	NENSFW(temp, ordinal);
	temp = realloc(temp, (strlen(ordinal) + 1) * sizeof(char));
	strcpy(temp, ordinal);
	numerical_to_ordinal(temp, ordinal);
	free(temp);
}
void NSFWSP(char *num_in, char *pair, int language_code)
{
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	if (language_code == 1)
	{
		normalize_number(num_in, temp);

		if (strcmp(temp, "55688") == 0)
		{
			NTISFW(temp, pair, language_code);
		}
		else if (strcmp(temp, "831") == 0)
		{
			strcpy(pair, CH_number[8]);
			strcat(pair, CH_number[3]);
			strcat(pair, one_yiao);
		}
		else if (strcmp(temp, "711") == 0)
		{
			strcpy(pair, CH_number[7]);
			strcat(pair, CH_number[1]);
			strcat(pair, CH_number[1]);
		}
		else if (temp[0] == '0')
		{
			strcat(pair, CH_number[2]);
			NTISFW(temp, pair, language_code);
		}
		else
		{
			// strcpy(pair, num_in);
			// if (strlen(temp)>=4)
			//{
			//	STFNVI(num_in, pair);
			// }
			// else
			//{
			//	NTNSFW(num_in, pair, 1);
			// }
			STFNVI(num_in, pair);
		}
	}
	else
	{
		if (utf8_word_length(num_in) < 7)
		{
			NENSFW(num_in, pair);
		}
		else
		{
			NEISFW(num_in, pair);
		}
	}

	free(temp);
}
void N2SWND(char *num_in, char *DPSPW, int language_code)
{
	int i, idx, zh1_flag = 0;
	char word[7], last_word[7]="";
	char *temp;

	if (language_code == 2)
	{
		NESWND(num_in, DPSPW, language_code);
		return;
	}
	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					if(strcmp(word, "之") == 0)
					{
						zh1_flag = 1;
					}
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (strcmp(last_word, "第") != 0 && (strcmp(temp, "2") == 0 || strcmp(temp, Number[12]) == 0) && isCJK_words(word) == 1 && zh1_flag == 0)
			{
				strcat(temp, word);
				// printf("%s\n", temp);
				NWMSFW(temp, &(DPSPW[strlen(DPSPW)]), 0);
			}
			else
			{
				DPTSFW(temp, &(DPSPW[strlen(DPSPW)]), 1);
				strcat(DPSPW, word);
			}
		}
		strcpy(last_word, word);
	}

	free(temp);
}
void TTFHSF(char *num_in, char *TTF, int language_code)
{
	strcat(TTF, CH_number[2]);
	strcat(TTF, UNIT[0]);
	strcat(TTF, CH_number[4]);
	strcat(TTF, ch_hour);
}
void HICTU8(char *num_in, char *UTF, int language_code)
{
	strcpy(UTF, html2utf8(num_in));
}
void FSFWTF(char *num_in, char *FRA, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			if (isDash(word) == 1 || isTilde(word) == 1)
			{
				strcat(FRA, ch_dao);
			}
			else
			{
				strcat(FRA, word);
			}
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0 && isSlash(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			FRACSFW(temp, &(FRA[strlen(FRA)]), 0);
			if (isDash(word) == 1 || isTilde(word) == 1)
			{
				strcat(FRA, ch_dao);
			}
			else
			{
				strcat(FRA, word);
			}
		}
	}

	free(temp);
}
void RSFWTF(char *num_in, char *RAT, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(RAT, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			DPTSFW(temp, &(RAT[strlen(RAT)]), 1);
			if (isColon(word) == 1)
			{
				strcat(RAT, ch_ratio);
			}
			else
			{
				strcat(RAT, word);
			}
		}
	}

	free(temp);
}
void NEIWND(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			if (strlen(DPSPW) > 0)
			{
				if (DPSPW[strlen(DPSPW) - 1] != ' ')
				{
					strcat(DPSPW, " ");
				}
			}
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			NEISFW(temp, &(DPSPW[strlen(DPSPW)]));
			strcat(DPSPW, word);
		}
	}

	free(temp);
}
void N2IWND(char *num_in, char *DPSPW, int language_code)
{
	int i, idx = 0;
	char word[7];
	char *temp;

	read_a_utf8_word(num_in, word, &idx);
	if (language_code == 2 && isL_Brackets(word) == 0)
	{
		NEIWND(num_in, DPSPW, language_code);
		return;
	}
	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			NTISFW(temp, &(DPSPW[strlen(DPSPW)]), language_code);
			strcat(DPSPW, word);
		}
	}

	free(temp);
}
void TADSRB(char *num_in, char *DPSPW, int language_code)
{
	int i, idx, patch_dao = 0, tidx, dash_flag = 0;
	char word[7];
	char middle_word[7], middle_word2[7], *sub_tmp;
	char **temp, *opt_tmp = (char *)malloc((strlen(num_in) + 1) * sizeof(char)), *removed_sp_temp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	float s2n[2];

	temp = (char **)malloc(3 * sizeof(char *));
	temp[0] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[1] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[2] = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	// printf("%s\n", num_in);
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		strcat(DPSPW, word);
	}
	for (temp[0][0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			patch_dao = 1;
			if (isDash(word) == 1)
			{
				dash_flag = 1;
			}
			strcpy(middle_word2, word);
			break;
		}
		else if (strcmp(word, ch_dao) == 0 || strcmp(word, ch_zh4) == 0)
		{
			strcpy(middle_word, word);
			break;
		}
		strcat(temp[0], word);
	}
	// printf("%s\n", temp[0]);
	for (tidx = 0, opt_tmp[0] = '\0'; read_a_utf8_word(temp[0], word, &tidx) == 0;)
	{
		if (isCJK_words(word) == 1 || isEnglish(word) == 1)
		{
			Retreat_a_utf8_word(temp[0], &tidx);
			strcpy(opt_tmp, &temp[0][tidx]);
			temp[0][tidx] = '\0';
			remove_space(temp[0]);
			break;
		}
	}
	// printf("%s\n", &(num_in[idx]));
	//for (temp[1][0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	//{
	//	if (isCJK_words(word) == 1 || isEnglish(word) == 1 || strcmp(word, "μ") == 0)
	//	{
	//		Retreat_a_utf8_word(num_in, &idx);
	//		strcpy(temp[2], &(num_in[idx]));
	//		remove_space(temp[1]);
	//		break;
	//	}
	//	strcat(temp[1], word);
	//}
	for (temp[1][0] = '\0', tidx = strlen(num_in); tidx > idx;)
	{
		Retreat_a_utf8_word(num_in, &tidx);
		read_a_utf8_word(num_in, word, &tidx);
		if (isNumber(word) == 1)
		{
			strncpy(temp[1], &(num_in[idx]), tidx - idx);
			temp[1][tidx - idx] = '\0';
			strcpy(temp[2], &(num_in[tidx]));
			remove_space(temp[1]);
			break;
		}
		else
		{
			Retreat_a_utf8_word(num_in, &tidx);
		}
	}
	s2n[0] = myatof(temp[0]);
	s2n[1] = myatof(temp[1]);
	strcpy(removed_sp_temp2,temp[2]);
	remove_space(removed_sp_temp2);
	// printf("%s [%s] %s %s(%s)\n", temp[0], opt_tmp, temp[1], temp[2], removed_sp_temp2);
	if(strlen(opt_tmp)>0 && strcmp(opt_tmp,removed_sp_temp2)!=0 && strcmp(Mandarin_day,removed_sp_temp2)!=0 && strcmp(Mandarin_month,removed_sp_temp2)!=0 && strcmp(Mandarin_year,removed_sp_temp2)!=0 && dash_flag==1)//5月-9回升到-0.8
	{
		if(strcmp(Mandarin_year,opt_tmp)==0)
		{
			STFNVI(temp[0], &(DPSPW[strlen(DPSPW)]));
		}
		else
		{
			DPTSFW(temp[0], &(DPSPW[strlen(DPSPW)]), 1);
		}
		strcat(DPSPW, opt_tmp);
		if(strcmp(opt_tmp,Mandarin_month)==0 || strcmp(opt_tmp,Mandarin_year)==0)
		{
			strcat(DPSPW, ch_negative);
		}
		else
		{
			strcat(DPSPW, middle_word2);
		}
		DPTSFW(temp[1], &(DPSPW[strlen(DPSPW)]), 1);
		strcat(DPSPW, temp[2]);
	}
	else if ((strncmp(temp[1], "2", 1) == 0 || strncmp(temp[1], Number[12], 3) == 0) && utf8_word_length(temp[1]) == 1)
	{
		STFNVI(temp[0], &(DPSPW[strlen(DPSPW)]));
		strcat(DPSPW, opt_tmp);
		if (patch_dao == 1)
		{
			strcat(&(DPSPW[strlen(DPSPW)]), ch_dao);
		}
		else
		{
			strcat(&(DPSPW[strlen(DPSPW)]), middle_word);
		}
		if (strncmp(removed_sp_temp2, Mandarin_month, 3) == 0 || strncmp(removed_sp_temp2, two_for_measure_word, 3) == 0 || strncmp(removed_sp_temp2, "號", 3) == 0 || strncmp(removed_sp_temp2, "樓", 3) == 0)
		{
			strcat(&(DPSPW[strlen(DPSPW)]), CH_number[2]);
		}
		else
		{
			strcat(&(DPSPW[strlen(DPSPW)]), two_for_measure_word);
		}
		strcat(&(DPSPW[strlen(DPSPW)]), temp[2]);
	}
	else if (strncmp(removed_sp_temp2, Mandarin_year, 3) == 0 && (utf8_word_length(temp[0]) == 4 || utf8_word_length(temp[1]) == 4 || utf8_word_length(temp[1]) == 2))
	{
		STFNVI(temp[0], &(DPSPW[strlen(DPSPW)]));
		strcat(DPSPW, opt_tmp);
		if (patch_dao == 1)
		{
			strcat(&(DPSPW[strlen(DPSPW)]), ch_dao);
		}
		else
		{
			strcat(&(DPSPW[strlen(DPSPW)]), middle_word);
		}
		if (strlen(temp[0]) > strlen(temp[1]))
		{
			NTISFW(temp[1], &(DPSPW[strlen(DPSPW)]), 0);
		}
		else
		{
			STFNVI(temp[1], &(DPSPW[strlen(DPSPW)]));
		}

		strcat(&(DPSPW[strlen(DPSPW)]), temp[2]);
	}
	else if (((s2n[0] >= 1000 && s2n[0] <= 2100 && s2n[1] - s2n[0] < 100) && (s2n[0] < s2n[1])) && has_dot(temp[0]) == 0 && has_dot(temp[1]) == 0)
	{
		N2IWND(temp[0], &(DPSPW[strlen(DPSPW)]), 1);
		strcat(DPSPW, opt_tmp);
		if (patch_dao == 1)
		{
			strcat(&(DPSPW[strlen(DPSPW)]), ch_dao);
		}
		else
		{
			strcat(&(DPSPW[strlen(DPSPW)]), middle_word);
		}
		N2IWND(temp[1], &(DPSPW[strlen(DPSPW)]), 1);
		strcat(&(DPSPW[strlen(DPSPW)]), temp[2]);
	}
	else
	{
		if ((strcmp(temp[0], "2") == 0 || strcmp(temp[0], Number[12]) == 0) && strlen(opt_tmp) > 0)
		{
			strcat(temp[0], opt_tmp);
			NWMSFW(temp[0], DPSPW, 0);
		}
		else
		{
			DPTSFW(temp[0], &(DPSPW[strlen(DPSPW)]), 1);
			strcat(DPSPW, opt_tmp);
		}
		if (patch_dao == 1)
		{
			if (s2n[0] < s2n[1] || dash_flag == 0 || strcmp(removed_sp_temp2, "μm") == 0 ||
				(strlen(opt_tmp) > 0 && strcmp(opt_tmp, removed_sp_temp2) != 0))
			{
				strcat(&(DPSPW[strlen(DPSPW)]), ch_dao);
			}
			else
			{
				strcat(&(DPSPW[strlen(DPSPW)]), ch_minus);
			}
		}
		else
		{
			strcat(&(DPSPW[strlen(DPSPW)]), middle_word);
		}
		DPTSFW(temp[1], &(DPSPW[strlen(DPSPW)]), 1);
		strcat(&(DPSPW[strlen(DPSPW)]), temp[2]);
	}

	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	free(opt_tmp);
	free(removed_sp_temp2);
}
int has_colon(char *line)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isColon(word) == 1)
		{
			return 1;
		}
	}
	return 0;
}
int has_slash(char *line)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isSlash(word) == 1)
		{
			return 1;
		}
	}
	return 0;
}
int has_number(char *line)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			return 1;
		}
	}
	return 0;
}
int has_mandarin(char *line)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isCJK_words(word) == 1)
		{
			return 1;
		}
	}
	return 0;
}
int has_dot(char *line)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isDot(word) == 1)
		{
			return 1;
		}
	}
	return 0;
}
int has_dot_numerals(char *line)
{
	int idx;
	char last_last_word[7]="", last_word[7]="", word[7]="";

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isNumber(last_last_word) == 1 && isDot(last_word) == 1 && isNumber(word) == 1)
		{
			return 1;
		}
		strcpy(last_last_word ,last_word);
		strcpy(last_word ,word);
	}
	return 0;
}
int has_comma(char *line)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isComma(word) == 1)
		{
			return 1;
		}
	}
	return 0;
}
int has_dash(char *line)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isDash(word) == 1)
		{
			return 1;
		}
	}
	return 0;
}
void normalize_date(char *num_in, char *nor_num_in)
{
	int i, idx, length, num_len;
	char word[7];

	for (nor_num_in[0] = '\0', idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			if (strlen(word) == 1) // half_type
			{
				strcat(nor_num_in, word);
			}
			else // fully_type
			{
				word[0] = word[2] + 112 + 48;
				word[1] = '\0';
				strcat(nor_num_in, word);
			}
		}
		else if (isDot(word))
		{
			strcat(nor_num_in, ".");
		}
		else if (isSlash(word))
		{
			strcat(nor_num_in, "/");
		}
		else if (isDash(word))
		{
			strcat(nor_num_in, "-");
		}
		else if (isTilde(word))
		{
			strcat(nor_num_in, "~");
		}
	}
}
void EMAILN(char *raw, char *modify, int language_code)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isCommercial_At(word) == 1)
		{
			strcat(modify, " at ");
		}
		else if (isDot(word) == 1)
		{
			strcat(modify, " dot ");
		}
		else if (isunder_line(word) == 1)
		{
			strcat(modify, ch_Under_Line);
		}
		else if (isDash(word) == 1)
		{
			strcat(modify, " dash ");
		}
		else if (isNumber(word) == 1)
		{
			strcat(modify, get_ch_Number(word));
		}
		else
		{
			strcat(modify, word);
		}
	}
}
char *get_ch_Number(char *word)
{
	int len = strlen(word);

	if (len == 1 && (word[0] >= 48 && word[0] <= 57))
	{
		return CH_number[word[0] - 48];
	}
	else if (len == 3 && word[0] == -17 && word[1] == -68 && (word[2] >= -112 && word[2] <= -103))
	{
		return CH_number[word[2] + 112];
	}

	return "";
}
char *get_eng_Number(char *word)
{
	int len = strlen(word);

	if (len == 1 && (word[0] >= 48 && word[0] <= 57))
	{
		return English_number[word[0] - 48];
	}
	else if (len == 3 && word[0] == -17 && word[1] == -68 && (word[2] >= -112 && word[2] <= -103))
	{
		return English_number[word[2] + 112];
	}

	return "";
}
void URLNOR(char *URL, char *nor_url, int language_code)
{
	int i, idx, ret, abyte_idx, abyte_capacity;
	char word[7], **abyte, twobyteutf8[3];
	char *temp = (char *)malloc((strlen(URL) + 1) * sizeof(char));

	abyte_capacity = ((int)(strlen(URL) / 3) + 1);
	abyte = (char **)malloc(abyte_capacity * sizeof(char *));
	for (i = 0; i < abyte_capacity; i++)
	{
		abyte[i] = (char *)malloc(19 * sizeof(char));
	}

	for (idx = 0; read_a_utf8_word(URL, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			if (isPercentage(word) == 1)
			{
				strcpy(abyte[0], word);
				read_a_utf8_word(URL, &(abyte[0][strlen(abyte[0])]), &idx);
				read_a_utf8_word(URL, &(abyte[0][strlen(abyte[0])]), &idx);
				for (abyte_idx = 1;;)
				{
					ret = read_a_utf8_word(URL, word, &idx);
					if (isPercentage(word) == 1)
					{
						strcpy(abyte[abyte_idx], word);
						read_a_utf8_word(URL, &(abyte[abyte_idx][strlen(abyte[abyte_idx])]), &idx);
						read_a_utf8_word(URL, &(abyte[abyte_idx][strlen(abyte[abyte_idx])]), &idx);
						abyte_idx++;
					}
					else
					{
						if (word[0] != '\0')
						{
							Retreat_a_utf8_word(URL, &idx);
						}
						break;
					}
				}
				for (i = 0, temp[0] = '\0'; i < abyte_idx; i++)
				{
					BYTRAN(abyte[i], &(temp[strlen(temp)]));
				}
				if (is_utf8_string(temp) == 0)
				{
					//for (i = 0, temp[0] = '\0'; i < abyte_idx; i++)
					//{
					//	word[0] = '\0';
					//	BYTRAN(abyte[i], word);
					//	strcpy(twobyteutf8, "00");
					//	twobyteutf8[0] = ((char)192) | ((int)(256 + word[0]) >> 6);
					//	twobyteutf8[1] = ((char)128) | (((int)(256 + word[0]) << 2) >> 2);
					//	// printf("abyte_idx=%d %s %d %d %d\n", abyte_idx, abyte[i], word[0], (unsigned)(twobyteutf8[0]), (unsigned)(twobyteutf8[1]));
					//	strcat(&(nor_url[strlen(nor_url)]), twobyteutf8);
					//}
					for (i = 0, temp[0] = '\0'; i < abyte_idx; i++)
					{
						strcat(temp, abyte[i]);
					}
					N2IWND(temp, &(nor_url[strlen(nor_url)]), language_code);
				}
				else
				{
					strcat(nor_url, temp);
				}
			}
			else if (isSlash(word) == 1)
			{
				strcat(nor_url, " slash ");
			}
			else if (isDot(word) == 1)
			{
				strcat(nor_url, " dot ");
			}
			else if (isampersand(word) == 1)
			{
				strcat(nor_url, " and ");
			}
			else if (isquestion(word) == 1)
			{
				strcat(nor_url, ch_question);
			}
			else if (isDash(word) == 1)
			{
				strcat(nor_url, " dash ");
			}
			else if (isequal_sign(word) == 1)
			{
				strcat(nor_url, ch_Equal_Sign);
			}
			else if (isunder_line(word) == 1)
			{
				strcat(nor_url, ch_Under_Line);
			}
			else if (isColon(word) == 1)
			{
				strcat(nor_url, ch_Colon);
			}
			else
			{
				strcat(nor_url, word);
			}
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(URL, word, &idx) == 0;)
			{
				if (isNumber(word) == 0)
				{
					Retreat_a_utf8_word(URL, &idx);
					break;
				}
				else
				{
					strcat(temp, word);
				}
			}
			// printf("%s\n", temp);
			NTISFW(temp, &(nor_url[strlen(nor_url)]), language_code);
			// strcat(nor_url, word);
		}
	}
	for (i = 0; i < abyte_capacity; i++)
	{
		free(abyte[i]);
	}
	free(abyte);
	free(temp);
}
void BYTRAN(char *raw, char *modify)
{
	int len = utf8_word_length(raw);
	char word[3][7] = {"", "", ""}, abyte;
	int idx = 0, upper, lower;

	read_a_utf8_word(raw, word[0], &idx);
	read_a_utf8_word(raw, word[1], &idx);
	read_a_utf8_word(raw, word[2], &idx);

	if (isPercentage(word[0]) == 1 && isheximalC(word[1]) == 1 && isheximalC(word[2]) == 1)
	{
		upper = get_heximal_val(word[1]);
		lower = get_heximal_val(word[2]);
		abyte = ((upper << 4) | lower);
		// printf("%s %s %s %d %d %d\n", word[0], word[1], word[2], upper, lower, abyte);
		modify[strlen(modify) + 1] = '\0';
		modify[strlen(modify)] = abyte;
	}
	else
	{
		if (isPercentage(word[0]) == 1)
		{
			strcat(modify, ch_paa);
		}
		else
		{
			strcat(modify, word[0]);
		}
		if (isNumber(word[1]) == 1)
		{
			if (strlen(word[1]) == 1)
			{
				strcat(modify, CH_number[word[1][0] - 48]);
			}
			else
			{
				strcat(modify, CH_number[word[1][2] + 112]);
			}
		}
		else
		{
			strcat(modify, word[1]);
		}
		if (isNumber(word[2]) == 1)
		{
			if (strlen(word[2]) == 1)
			{
				strcat(modify, CH_number[word[2][0] - 48]);
			}
			else
			{
				strcat(modify, CH_number[word[2][2] + 112]);
			}
		}
		else
		{
			strcat(modify, word[2]);
		}
	}
}
int get_heximal_val(char *word)
{
	int ret = -1;
	int len = strlen(word);

	if (len == 1)
	{
		if (word[0] >= 48 && word[0] <= 57)
		{
			return word[0] - 48;
		}
		else if (word[0] >= 65 && word[0] <= 70)
		{
			return word[0] - 55;
		}
	}
	else if (len == 3)
	{
		if (word[0] == -17 && word[1] == -68)
		{
			if (word[2] >= -112 && word[2] <= -103)
			{
				return word[2] + 112;
			}
			else if (word[2] >= -95 && word[2] <= -90)
			{
				return word[2] + 105;
			}
		}
	}

	return ret;
}
int isheximalC(char *word)
{
	int len = strlen(word);

	if (len == 1)
	{
		if ((word[0] >= 48 && word[0] <= 57) || (word[0] >= 65 && word[0] <= 70))
		{
			return 1;
		}
	}
	else if (len == 3)
	{
		if (word[0] == -17 && word[1] == -68)
		{
			if ((word[2] >= -112 && word[2] <= -103) || (word[2] >= -95 && word[2] <= -90))
			{
				return 1;
			}
		}
	}

	return 0;
}
void DPESFW(char *num_in, char *DPSPW)
{
	int idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDot(word) == 0)
		{
			strcat(temp, word);
		}
		else
		{
			break;
		}
	}
	NENSFW(temp, DPSPW);
	if (has_number(&(num_in[idx])) == 1)
	{
		strcat(&(DPSPW[strlen(DPSPW)]), "point ");
		NEISFW(&(num_in[idx]), &(DPSPW[strlen(DPSPW)]));
	}
	free(temp);
}
void NENSFW(char *raw, char *modify)
{
	int idx, unit_idx, temp_idx, temp_len, tok_len, remainder;
	char *temp = (char *)malloc((strlen(raw) + 1) * sizeof(char));
	char tok[4];
	int i, val, flag;
	normalize_number(raw, temp);
	temp_len = strlen(temp);

	if (temp_len > 33)
	{
		NEISFW(raw, modify);
		free(temp);
		return;
	}
	else if (temp_len == 0)
	{
		return;
	}

	for (temp_idx = 0; temp[temp_idx] == '0' && temp_idx < temp_len; temp_idx++)
	{
		continue;
	}
	if (temp_idx == temp_len)
	{
		Retreat_a_utf8_word(temp, &temp_idx);
		strcat(modify, English_number[0]);
		strcat(modify, " ");
	}
	// printf("%s\n", temp);

	for (unit_idx = (temp_len - temp_idx - 1) / 3, remainder = temp_len - temp_idx; unit_idx >= 0; unit_idx--, remainder -= tok_len)
	{
		tok[0] = tok[1] = tok[2] = '0';
		flag = 0;
		tok_len = (remainder % 3) == 0 ? 3 : remainder % 3;
		for (i = 0; i < tok_len; i++)
		{
			tok[3 - i - 1] = temp[temp_idx + tok_len - i - 1];
		}
		tok[3] = '\0';
		temp_idx += tok_len;
		// printf("%s\n", tok);
		if (tok[0] != '0')
		{
			strcat(modify, English_number[tok[0] - 48]);
			strcat(modify, " ");
			strcat(modify, English_hundred);
			strcat(modify, " ");
			flag = 1;
		}
		val = (tok[1] - 48) * 10 + tok[2] - 48;
		// printf("%d ", val);
		if (val > 0 && val < 10)
		{
			strcat(modify, English_number[tok[2] - 48]);
			strcat(modify, " ");
			flag = 1;
		}
		else if (val >= 10 && val < 20)
		{
			strcat(modify, English_teens[val - 10]);
			strcat(modify, " ");
			flag = 1;
		}
		else if (val >= 20)
		{
			strcat(modify, English_tys[tok[1] - 50]);
			if (tok[2] != '0')
			{
				strcat(modify, "-");
				strcat(modify, English_number[tok[2] - 48]);
				strcat(modify, " ");
			}
			else
			{
				strcat(modify, " ");
			}
			flag = 1;
		}
		if (flag == 1 && unit_idx > 0)
		{
			strcat(modify, English_unit[unit_idx - 1]);
			strcat(modify, " ");
		}
	}

	free(temp);
}
void NEISFW(char *raw, char *modify)
{
	int idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			strcat(modify, get_eng_Number(word));
			strcat(modify, " ");
		}
	}
}
void MDWNDI(char *num_in, char *MDS, int language_code)
{
	int idx, sidx, pre_idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (sidx = 0, MDS[0] = '\0'; read_a_utf8_word(num_in, word, &sidx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			break;
		}
		else
		{
			strcat(MDS, word);
		}
	}
	Retreat_a_utf8_word(num_in, &sidx);
	for (idx = sidx; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isSlash(word) == 0)
		{
			break;
		}
	}
	pre_idx = idx;
	Retreat_a_utf8_word(num_in, &pre_idx);
	strncpy(temp, &num_in[sidx], pre_idx - sidx);
	temp[pre_idx - sidx] = '\0';
	// printf("%s %s\n", num_in, temp);
	MDTSFW(temp, &(MDS[strlen(MDS)]));
	if (strncmp(&(num_in[pre_idx]), Mandarin_day, 3) == 0 || strncmp(&(num_in[pre_idx]), Mandarin_number, 3) == 0)
	{
		MDS[strlen(MDS) - 3] = '\0';
		N2IWND(&(num_in[pre_idx]), &(MDS[strlen(MDS)]), language_code);
	}
	else if (isL_Brackets(word) == 1)
	{
		add_day_suffix(&num_in[pre_idx], MDS);
	}
	else
	{
		N2IWND(&(num_in[pre_idx]), &(MDS[strlen(MDS)]), language_code);
	}
	free(temp);
}
void HMTSFW(char *num_in, char *MDS, int language_code)
{
	int idx = 0, temp_idx, com_idx, size;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	if (has_colon(num_in) == 1)
	{
		for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isColon(word) == 1)
			{
				break;
			}
			else if (isNumber(word) == 1)
			{
				strcat(temp, word);
			}
			else
			{
				strcat(MDS, word);
			}
		}
		for (temp_idx = 0; read_a_utf8_word(temp, word, &temp_idx) == 0;)
		{
			if (isNon_zero_number(word) == 1)
			{
				break;
			}
		}
		Retreat_a_utf8_word(temp, &temp_idx);
		for (com_idx = temp_idx, size = 0; read_a_utf8_word(temp, word, &com_idx) == 0;)
		{
			if (isNumber(word) == 1)
			{
				size++;
			}
		}
		NTNSFW(&(temp[temp_idx]), &(MDS[strlen(MDS)]), 1);
		strcat(&(MDS[strlen(MDS)]), CH_point);
	}

	strcpy(temp, &(num_in[idx]));
	for (temp_idx = 0; read_a_utf8_word(temp, word, &temp_idx) == 0;)
	{
		if (isNon_zero_number(word) == 1)
		{
			break;
		}
	}
	Retreat_a_utf8_word(temp, &temp_idx);

	for (com_idx = temp_idx, size = 0; read_a_utf8_word(temp, word, &com_idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			size++;
		}
	}
	if (isNon_zero_number(&(temp[temp_idx])) == 1 || utf8_word_length(&(temp[temp_idx])) != 1)
	{
		if (strncmp(&temp[temp_idx], Number[2], strlen(Number[2])) == 0 || strncmp(&temp[temp_idx], Number[12], strlen(Number[12])) == 0)
		{
			NTNSFW(&(temp[temp_idx]), &(MDS[strlen(MDS)]), 0);
		}
		else
		{
			NTNSFW(&(temp[temp_idx]), &(MDS[strlen(MDS)]), 1);
		}
		strcat(&(MDS[strlen(MDS)]), ch_feng);
	}

	free(temp);
}
void MDTSFW(char *num_in, char *MDS)
{
	int idx = 0, temp_idx, com_idx, size;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	if (has_slash(num_in) == 1 || has_dot(num_in) == 1 || has_dash(num_in) == 1)
	{
		for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isSlash(word) == 1 || isDot(word) == 1 || isDash(word) == 1)
			{
				break;
			}
			strcat(temp, word);
		}
		for (temp_idx = 0; read_a_utf8_word(temp, word, &temp_idx) == 0;)
		{
			if (isNon_zero_number(word) == 1)
			{
				break;
			}
		}
		Retreat_a_utf8_word(temp, &temp_idx);
		for (com_idx = temp_idx, size = 0; read_a_utf8_word(temp, word, &com_idx) == 0;)
		{
			if (isNumber(word) == 1)
			{
				size++;
			}
		}
		if (size > 1)
		{
			NTNSFW(&(temp[temp_idx]), &(MDS[strlen(MDS)]), 1);
		}
		else
		{
			NTNSFW(&(temp[temp_idx]), &(MDS[strlen(MDS)]), 0);
		}
		strcat(&(MDS[strlen(MDS)]), Mandarin_month);
	}

	strcpy(temp, &(num_in[idx]));
	for (temp_idx = 0; read_a_utf8_word(temp, word, &temp_idx) == 0;)
	{
		if (isNon_zero_number(word) == 1)
		{
			break;
		}
	}
	Retreat_a_utf8_word(temp, &temp_idx);
	for (com_idx = temp_idx, size = 0; read_a_utf8_word(temp, word, &com_idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			size++;
		}
	}
	if (size > 1)
	{
		NTNSFW(&(temp[temp_idx]), &(MDS[strlen(MDS)]), 1);
	}
	else
	{
		NTNSFW(&(temp[temp_idx]), &(MDS[strlen(MDS)]), 0);
	}
	idx = strlen(num_in);
	Retreat_a_utf8_word(num_in, &idx);
	read_a_utf8_word(num_in, word, &idx);
	// printf("HERE:%s\n",num_in);
	strcat(&(MDS[strlen(MDS)]), retdaynum());

	free(temp);
}
void DMTSFW(char *num_in, char *DMS)
{
	int idx = 0, temp_idx[2], com_idx, size[2];
	char word[7];
	char *temp1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *temp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	if (has_slash(num_in) == 1)
	{
		for (idx = 0, temp1[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isSlash(word) == 1)
			{
				break;
			}
			strcat(temp1, word);
		}
		for (temp_idx[0] = 0; read_a_utf8_word(temp1, word, &temp_idx[0]) == 0;)
		{
			if (isNon_zero_number(word) == 1)
			{
				break;
			}
		}
		Retreat_a_utf8_word(temp1, &temp_idx[0]);
		for (com_idx = temp_idx[0], size[0] = 0; read_a_utf8_word(temp1, word, &com_idx) == 0;)
		{
			if (isNumber(word) == 1)
			{
				size[0]++;
			}
		}
	}

	strcpy(temp2, &(num_in[idx]));
	for (temp_idx[1] = 0; read_a_utf8_word(temp2, word, &temp_idx[1]) == 0;)
	{
		if (isNon_zero_number(word) == 1)
		{
			break;
		}
	}
	Retreat_a_utf8_word(temp2, &temp_idx[1]);
	for (com_idx = temp_idx[1], size[1] = 0; read_a_utf8_word(temp2, word, &com_idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			size[1]++;
		}
	}

	if (size[1] > 1)
	{
		NTNSFW(&(temp2[temp_idx[1]]), &(DMS[strlen(DMS)]), 1);
	}
	else
	{
		NTNSFW(&(temp2[temp_idx[1]]), &(DMS[strlen(DMS)]), 0);
	}
	strcat(&(DMS[strlen(DMS)]), Mandarin_month);

	if (size[0] > 1)
	{
		NTNSFW(&(temp1[temp_idx[0]]), &(DMS[strlen(DMS)]), 1);
	}
	else
	{
		NTNSFW(&(temp1[temp_idx[0]]), &(DMS[strlen(DMS)]), 0);
	}

	idx = strlen(num_in);
	Retreat_a_utf8_word(num_in, &idx);
	read_a_utf8_word(num_in, word, &idx);
	// printf("HERE:%s\n",num_in);
	strcat(&(DMS[strlen(DMS)]), retdaynum());

	free(temp1);
	free(temp2);
}
void HMTOHM(char *num_in, char *MDS, int language_code)
{
	int idx, pre_idx, middle_word_flag=0;
	char word[7], middle_word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1 || strcmp(word, ch_dao) == 0 || strcmp(word, ch_zh4) == 0)
		{
			if(strcmp(word, ch_dao) == 0 || strcmp(word, ch_zh4) == 0)
			{
				middle_word_flag = 1;
				strcpy(middle_word, word);
			}
			break;
		}
	}
	pre_idx = idx;
	Retreat_a_utf8_word(num_in, &pre_idx);
	strncpy(temp, num_in, pre_idx);
	temp[pre_idx] = '\0';
	HMTSFW(temp, &(MDS[strlen(MDS)]), language_code);
	if(middle_word_flag==0)
	{
		strcat(&(MDS[strlen(MDS)]), ch_dao);
	}
	else
	{
		strcat(&(MDS[strlen(MDS)]), middle_word);
	}
	strcpy(temp, &(num_in[idx]));
	HMTSFW(temp, &(MDS[strlen(MDS)]), language_code);
	free(temp);
}
void MDTOMD(char *num_in, char *MDS, int language_code)
{
	int idx, pre_idx, marks_num = 0;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *sub = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			break;
		}
		strcat(MDS, word);
	}
	Retreat_a_utf8_word(num_in, &idx);
	strcpy(sub, &num_in[idx]);
	for (idx = 0; read_a_utf8_word(sub, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isDot(word) == 1 || isSlash(word) == 1)
		{
			marks_num++;
		}
		if ((isDash(word) == 1 && marks_num == 2) || isTilde(word) == 1)
		{
			break;
		}
	}
	pre_idx = idx;
	Retreat_a_utf8_word(sub, &pre_idx);
	strcpy(temp, sub);
	temp[pre_idx] = '\0';
	MDTSFW(temp, &(MDS[strlen(MDS)]));
	// printf("%s\n", temp);
	strcpy(temp, &(sub[idx]));
	strcat(&(MDS[strlen(MDS)]), ch_dao);
	MDTSFW(temp, &(MDS[strlen(MDS)]));
	// printf("%s\n", temp);
	free(temp);
	free(sub);
}
void DMTODM(char *num_in, char *DMS, int language_code)
{
	int idx, pre_idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *sub = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			break;
		}
		strcat(DMS, word);
	}
	Retreat_a_utf8_word(num_in, &idx);
	strcpy(sub, &num_in[idx]);
	for (idx = 0; read_a_utf8_word(sub, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			break;
		}
	}
	pre_idx = idx;
	Retreat_a_utf8_word(sub, &pre_idx);
	strncpy(temp, sub, pre_idx);
	temp[pre_idx] = '\0';
	DMTSFW(temp, &(DMS[strlen(DMS)]));
	// printf("%s\n", temp);
	strcpy(temp, &(sub[idx]));
	strcat(&(DMS[strlen(DMS)]), ch_dao);
	DMTSFW(temp, &(DMS[strlen(DMS)]));
	// printf("%s\n", temp);
	free(temp);
	free(sub);
}
void COMPRO(char *num_in, char *PRO, int language_code)
{
	int idx, pre_idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDot(word) == 1)
		{
			break;
		}
	}
	pre_idx = idx;
	Retreat_a_utf8_word(num_in, &pre_idx);
	strncpy(temp, num_in, pre_idx);
	temp[pre_idx] = '\0';
	NTISFW(temp, &(PRO[strlen(PRO)]), 0);
	// printf("%s\n", temp);
	strcpy(temp, &(num_in[idx]));
	strcat(&(PRO[strlen(PRO)]), CH_point);
	CH_N2SWND(temp, &(PRO[strlen(PRO)]), language_code);
	// printf("%s\n", temp);
	free(temp);
}
void NTONPG(char *num_in, char *PER, int language_code)
{
	int idx, pre_idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			break;
		}
	}
	pre_idx = idx;
	Retreat_a_utf8_word(num_in, &pre_idx);
	strncpy(temp, num_in, pre_idx);
	temp[pre_idx] = '\0';
	DPTSFW(temp, &(PER[strlen(PER)]), 1);
	// printf("%s\n", temp);
	strcpy(temp, &(num_in[idx]));
	strcat(&(PER[strlen(PER)]), ch_dao);
	DPTSFW(temp, &(PER[strlen(PER)]), 1);
	// printf("%s\n", temp);
	free(temp);
}
void STFNVI(char *num_in, char *RES)
{
	char *NER = (char *)malloc((strlen(num_in) * 6 + 1) * sizeof(char));
	char *IND = (char *)malloc((strlen(num_in) * 3 + 1) * sizeof(char));
	char word[7];
	int idx = 0;

	NTNSFW(num_in, NER, 1);
	NTISFW(num_in, IND, 0);

	read_a_utf8_word(num_in, word, &idx);

	/**************************************************************************************/
	if (strcmp(word, Number[0]) == 0 || strcmp(word, Number[10]) == 0)
	{
		strcpy(RES, IND);
	}
	/**************************************************************************************/
	else if (strlen(NER) < strlen(IND))
	{
		strcpy(RES, NER);
	}
	else if (strlen(NER) == strlen(IND))
	{
		if (utf8_word_length(num_in) == 2 && (strcmp(word, Number[0]) != 0 && strcmp(word, Number[10]) != 0))
		{
			strcpy(RES, NER);
		}
		else
		{
			strcpy(RES, IND);
		}
	}
	else
	{
		strcpy(RES, IND);
	}

	free(NER);
	free(IND);
}
void SFWFSC(char *num_in, char *RES, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(RES, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (strncmp(temp, "0", 1) == 0 || strncmp(temp, Number[10], 3) == 0)
			{
				NTISFW(temp, &(RES[strlen(RES)]), 0);
			}
			else
			{
				STFNVI(temp, &(RES[strlen(RES)]));
			}
			strcat(RES, word);
		}
	}

	free(temp);
}
char *html2utf8(char *hcode)
{
	char *nor_hcode = (char *)malloc((strlen(hcode) + 1) * sizeof(char));
	int i, idx;
	static char word[7];
	int unicode_value = 0;
	static int unicode_range[4][2] = {{0, 127}, {128, 2047}, {2048, 65535}, {65536, 1114111}};
	static int unicode_len[4] = {7, 11, 16, 21};
	static char utf8_prefix[4] = {128, 192, 224, 240};
	int temp;

	for (i = idx = 0; read_a_utf8_word(hcode, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			if (strlen(word) == 1)
			{
				nor_hcode[i] = word[0];
			}
			else
			{
				nor_hcode[i] = word[2] + 112 + 48;
			}
			i++;
		}
	}
	nor_hcode[i] = '\0';
	// printf("%s\n", nor_hcode);
	unicode_value = atoi(nor_hcode);
	if (unicode_value >= unicode_range[0][0] && unicode_value <= unicode_range[0][1])
	{
		word[0] = (char)unicode_value;
	}
	else if (unicode_value >= unicode_range[1][0] && unicode_value <= unicode_range[1][1])
	{
		word[0] = utf8_prefix[1];
		temp = unicode_value >> 6;
		word[0] = word[0] | (char)temp;
		word[1] = utf8_prefix[0];
		temp = unicode_value & 63; // 00111111
		word[1] = word[1] | (char)temp;
		word[2] = '\0';
	}
	else if (unicode_value >= unicode_range[2][0] && unicode_value <= unicode_range[2][1])
	{
		word[0] = utf8_prefix[2];
		temp = unicode_value >> 12;
		word[0] = word[0] | (char)temp;
		word[1] = utf8_prefix[0];
		temp = unicode_value & 4032; // 0000111111000000
		temp = temp >> 6;
		word[1] = word[1] | (char)temp;
		word[2] = utf8_prefix[0];
		temp = unicode_value & 63; // 00111111
		word[2] = word[2] | (char)temp;
		word[3] = '\0';
	}
	else if (unicode_value >= unicode_range[3][0] && unicode_value <= unicode_range[3][1])
	{
		word[0] = utf8_prefix[3];
		temp = unicode_value >> 18;
		word[0] = word[0] | (char)temp;
		word[1] = utf8_prefix[0];
		temp = unicode_value & 258048; // 000111111000000000000
		temp = temp >> 12;
		word[1] = word[1] | (char)temp;
		word[2] = utf8_prefix[0];
		temp = unicode_value & 4032; // 0000111111000000
		temp = temp >> 6;
		word[2] = word[2] | (char)temp;
		word[3] = utf8_prefix[0];
		temp = unicode_value & 63; // 00111111
		word[3] = word[3] | (char)temp;
		word[4] = '\0';
	}
	else
	{
		// printf("%s out of unicode range.\n", hcode);
		free(nor_hcode);
		// exit(1);
		return hcode;
	}
	// printf("%d %d %d %s\n", word[0], word[1], word[2], word);
	// printf("%d %d %d %d\n", utf8_prefix[0], utf8_prefix[1], utf8_prefix[2], utf8_prefix[3]);

	free(nor_hcode);
	return word;
}
char *retdaynum()
{
	int val = rand() % 2;

	if (val == 0)
	{
		return Mandarin_day;
	}
	else
	{
		return Mandarin_number;
	}
}
int decide_language(char *line, NSW_TOKEN *nsw)
{
	int nsw_idx = nsw->size - 1, idx, forward_idx, backward_idx, idx_tmp;
	char word[7];
	int ch_flag, eng_flag, forward_language, backward_language;

	for (idx = 0, ch_flag = eng_flag = 0; read_a_utf8_word(nsw->token[nsw_idx], word, &idx) == 0;)
	{
		if (isCJK_words(word) == 1)
		{
			ch_flag = 1;
		}
		else if (isEnglish(word) == 1)
		{
			eng_flag = 1;
		}
	}
	if (ch_flag == 1)
	{
		return 1;
	}
	else if (eng_flag == 1)
	{
		return 2;
	}

	for (forward_language = 0, forward_idx = nsw->start_idx[nsw_idx]; Retreat_a_utf8_word(line, &forward_idx) != 0;)
	{
		idx_tmp = forward_idx;
		read_a_utf8_word(line, word, &idx_tmp);
		if (isCJK_words(word) == 1)
		{
			forward_language = 1;
			break;
		}
		else if (isEnglish(word) == 1)
		{
			forward_language = 2;
			break;
		}
	}
	for (backward_language = 0, backward_idx = nsw->end_idx[nsw_idx]; read_a_utf8_word(line, word, &backward_idx) == 0;)
	{
		if (isCJK_words(word) == 1)
		{
			backward_language = 1;
			break;
		}
		else if (isEnglish(word) == 1)
		{
			backward_language = 2;
			break;
		}
	}
	if (forward_language == 1)
	{
		return 1;
	}
	else if (forward_language == 2)
	{
		return 2;
	}
	else if (backward_language == 1)
	{
		return 1;
	}
	else if (backward_language == 2)
	{
		return 2;
	}

	return 1;
}
int decide_language_by_sentence(char *line, NSW_TOKEN *nsw)
{
	int ch_num = 0, eng_num = 0;
	int forward_idx, backward_idx, idx_tmp, nsw_idx = nsw->size - 1;
	int eng_flag;
	char word[7];

	for (forward_idx = nsw->start_idx[nsw_idx], eng_flag = 0; Retreat_a_utf8_word(line, &forward_idx) != 0;)
	{
		idx_tmp = forward_idx;
		read_a_utf8_word(line, word, &idx_tmp);
		if (isEnglish(word) == 1)
		{
			eng_flag = 1;
		}
		else
		{
			if (isCJK_words(word) == 1)
			{
				ch_num++;
			}
			if (eng_flag == 1)
			{
				eng_num++;
				eng_flag = 0;
			}
			if (issplited_mark(word) == 1)
			{
				break;
			}
		}
	}
	for (backward_idx = nsw->end_idx[nsw_idx]; read_a_utf8_word(line, word, &backward_idx) == 0;)
	{
		if (isEnglish(word) == 1)
		{
			eng_flag = 1;
		}
		else
		{
			if (isCJK_words(word) == 1)
			{
				ch_num++;
			}
			if (eng_flag == 1)
			{
				eng_num++;
				eng_flag = 0;
			}
			if (issplited_mark(word) == 1)
			{
				break;
			}
		}
	}
	if (ch_num >= eng_num)
	{
		return 1;
	}
	else
	{
		return 2;
	}

	return 1;
}
void insert_string(char *line, char *prev, char *next, char *insert_s)
{
	if (isspaces(prev) == 0)
	{
		strcat(line, " ");
	}
	strcat(line, insert_s);
	if (isspaces(next) == 0 && next[0] != '\0')
	{
		strcat(line, " ");
	}
}
void numerical_to_ordinal(char *in, char *out)
{
	int i, last_start_idx;
	char *temp = malloc((strlen(in) + 1) * sizeof(char));
	char *last = malloc((strlen(in) + 1) * sizeof(char));

	strcpy(temp, in);
	for (i = strlen(temp) - 1; i >= 0; i--)
	{
		if (temp[i] == ' ')
		{
			temp[i] = '\0';
		}
		else
		{
			break;
		}
	}
	for (last_start_idx = strlen(temp); last_start_idx >= 0; last_start_idx--)
	{
		if (temp[last_start_idx] == ' ' || temp[last_start_idx] == '-')
		{
			break;
		}
	}
	last_start_idx++;

	strcpy(last, &temp[last_start_idx]);
	// printf("last_start_idx=%d last=%s out[last_start_idx]=%s\n", last_start_idx, last, &out[last_start_idx]);
	strcpy(out, temp);
	if (strlen(last) < 3)
	{
	}
	else if (strcmp(last, "one") == 0)
	{
		strcpy(&out[last_start_idx], "first");
	}
	else if (strcmp(last, "two") == 0)
	{
		strcpy(&out[last_start_idx], "second");
	}
	else if (strcmp(last, "three") == 0)
	{
		strcpy(&out[last_start_idx], "third");
	}
	else if (strcmp(&last[strlen(last) - 2], "ve") == 0)
	{
		strcpy(&out[last_start_idx + strlen(last) - 2], "fth");
	}
	else if (strcmp(&last[strlen(last) - 1], "t") == 0)
	{
		strcpy(&out[last_start_idx + strlen(last) - 1], "th");
	}
	else if (strcmp(&last[strlen(last) - 1], "y") == 0)
	{
		strcpy(&out[last_start_idx + strlen(last) - 1], "ieth");
	}
	else
	{
		strcat(out, "th");
	}

	free(last);
	free(temp);
}
void PRNTPG(char *raw, char *modify, int language_code)
{
	int rnsi;
	char *arabic_num;
	char *eng_num;
	char *eng_num_ord;

	for (rnsi = strlen(raw); raw[rnsi] != ' ' && raw[rnsi] != '\t' && rnsi >= 0; rnsi--)
	{
		continue;
	}
	rnsi++;
	arabic_num = (char *)malloc(strlen(&raw[rnsi]) * 16 * sizeof(char));
	roman_num2arabic_num(&raw[rnsi], arabic_num);
	// printf("%s %s\n", &raw[rnsi], arabic_num);
	eng_num = (char *)malloc(strlen(arabic_num) * 32 * sizeof(char));
	eng_num[0] = '\0';
	NENSFW(arabic_num, eng_num);
	// printf("%s %s %s\n", &raw[rnsi], arabic_num, eng_num);
	eng_num_ord = (char *)malloc(strlen(arabic_num) * 32 * sizeof(char));
	numerical_to_ordinal(eng_num, eng_num_ord);
	// printf("%s %s %s %s\n", &raw[rnsi], arabic_num, eng_num, eng_num_ord);

	strcpy(modify, raw);
	modify[rnsi] = '\0';
	strcat(modify, "the ");
	strcat(modify, eng_num_ord);
	strcat(modify, " ");

	free(arabic_num);
	free(eng_num);
	free(eng_num_ord);
}
void roman_num2arabic_num(char *in, char *out)
{
	// I=1,V=5,X=10,L=50,C=100,D=500,M=1000
	// up to 3999
	int idx, token_num;
	char word[7];
	char *roman_num, *temp;
	int arabic_num;

	for (idx = token_num = 0; read_a_utf8_word(in, word, &idx) == 0;)
	{
		token_num++;
	}
	idx = 0;
	read_a_utf8_word(in, word, &idx);
	if (isEnglish(word) == 1)
	{
		roman_num = (char *)malloc((token_num + 1) * sizeof(char));
		normalize_english_uppercase(in, roman_num);
		// printf("%s\n", roman_num);
	}
	else
	{
		temp = (char *)malloc((token_num * 4 + 1) * sizeof(char));
		roman_num = (char *)malloc((token_num * 4 + 1) * sizeof(char));
		RACTEA(in, temp, 0);
		normalize_english_uppercase(temp, roman_num);
		free(temp);
	}
	arabic_num = roman_num_converter(roman_num);
	// printf("%s %d\n", roman_num, arabic_num);
	sprintf(out, "%d", arabic_num);

	free(roman_num);
}
void RACTEA(char *roman_alphabet, char *english_alphabet, int language_code)
{
	int i, idx;
	char word[7];

	english_alphabet[0] = '\0';
	for (idx = 0; read_a_utf8_word(roman_alphabet, word, &idx) == 0;)
	{
		for (i = 0; i < 32; i++)
		{
			if (strcmp(word, Roman_numerals[i][0]) == 0)
			{
				strcat(english_alphabet, Roman_numerals[i][1]);
				break;
			}
		}
	}
}
void CMNTSW(char *raw, char *modify, int language_code)
{
	int i, idx;
	char word[7];

	modify[0] = '\0';
	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (strcmp(word, Mandarin_decimal_point) == 0)
		{
			strcat(modify, CH_point);
		}
		else
		{
			strcat(modify, word);
		}
	}
}
void CMFSFW(char *raw, char *modify, int language_code)
{
	int i, idx;
	char word[7];
	char *N_raw = (char *)malloc((strlen(raw) + 1) * sizeof(char));
	char *temp = (char *)malloc((strlen(raw) + 1) * sizeof(char));
	char *temp2 = (char *)malloc((strlen(raw) + 1) * sizeof(char));

	for (idx = 0, N_raw[0] = '\0'; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isspaces(word) == 0)
		{
			strcat(N_raw, word);
		}
	}
	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(N_raw, word, &idx) == 0;)
	{
		if (isPlus(word) == 1)
		{
			N2SWND(temp, &modify[strlen(modify)], language_code);
			temp[0] = '\0';
			if (language_code == 1)
			{
				strcat(modify, ch_plus);
			}
			else
			{
				strcat(modify, "plus ");
			}
		}
		else if (isDash(word) == 1)
		{
			N2SWND(temp, &modify[strlen(modify)], language_code);
			temp[0] = '\0';
			if (language_code == 1)
			{
				strcat(modify, ch_minus);
			}
			else
			{
				strcat(modify, "minus ");
			}
		}
		else if (ismultiple_sign(word) == 1)
		{
			N2SWND(temp, &modify[strlen(modify)], language_code);
			temp[0] = '\0';
			if (language_code == 1)
			{
				strcat(modify, "乘");
			}
			else
			{
				strcat(modify, "multiply by ");
			}
		}
		else if (strcmp(divide_sign, word) == 0)
		{
			N2SWND(temp, &modify[strlen(modify)], language_code);
			temp[0] = '\0';
			if (language_code == 1)
			{
				strcat(modify, ch_divide_by);
			}
			else
			{
				strcat(modify, "devide by ");
			}
		}
		else if (isSlash(word) == 1)
		{
			for (temp2[0] = '\0'; read_a_utf8_word(N_raw, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isComma(word) == 0 && isDot(word) == 0)
				{
					Retreat_a_utf8_word(N_raw, &idx);
					break;
				}
				strcat(temp2, word);
			}

			if (language_code == 1)
			{
				N2SWND(temp2, &modify[strlen(modify)], language_code);
				strcat(modify, "分之");
				N2SWND(temp, &modify[strlen(modify)], language_code);
			}
			else
			{
				N2SWND(temp, &modify[strlen(modify)], language_code);
				strcat(modify, "over ");
				N2SWND(temp2, &modify[strlen(modify)], language_code);
			}

			temp[0] = temp2[0] = '\0';
		}
		else if (isequal_sign(word) == 1)
		{
			N2SWND(temp, &modify[strlen(modify)], language_code);
			temp[0] = '\0';
			if (language_code == 1)
			{
				strcat(modify, ch_euqal);
			}
			else
			{
				strcat(modify, "equal ");
			}
		}
		else if (isCJK_words(word) == 1)
		{
			N2SWND(temp, &modify[strlen(modify)], language_code);
			temp[0] = '\0';
			strcat(modify, word);
		}
		else
		{
			strcat(temp, word);
		}
	}
	N2SWND(temp, &modify[strlen(modify)], language_code);

	free(N_raw);
	free(temp);
	free(temp2);
}
void GFGCAS(char *raw, char *modify, int language_code)
{
	int i, idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isPlus(word) == 1)
		{
			strcat(modify, ch_plus);
		}
		else if (isDash(word) == 1)
		{
			strcat(modify, ch_minus);
		}
		else if (ismultiple_sign(word) == 1)
		{
			strcat(modify, ch_multiply_by);
		}
		else if (isSlash(word) == 1 || strcmp(divide_sign, word) == 0)
		{
			strcat(modify, ch_divide_by);
		}
		else if (isequal_sign(word) == 1)
		{
			strcat(modify, ch_euqal);
		}
		else
		{
			strcat(modify, word);
		}
	}
}
void CASSWA(char *raw, char *modify, int language_code)
{
	int i, idx, M_flag = 0;
	char word[7];
	char Manarin_and[4] = {-27, -110, -116, '\0'}; /** 和**/

	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isCJK_words(word) == 1)
		{
			M_flag = 1;
			break;
		}
	}

	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isampersand(word) == 1)
		{
			if (M_flag == 1)
			{
				strcat(modify, Manarin_and);
			}
			else
			{
				strcat(modify, " and ");
			}
		}
		else
		{
			strcat(modify, word);
		}
	}
}
void ECCWPS(char *raw, char *modify, int language_code)
{
	int i, idx;
	char word[7];

	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isPlus(word) == 1)
		{
			strcat(modify, " plus");
		}
		else if (isNumber_sign(word) == 1)
		{
			strcat(modify, " sharp");
		}
		else
		{
			strcat(modify, word);
		}
	}
}
void ABOYTY(char *raw, char *modify, int language_code)
{
	int i, idx, csize;
	char word[7], year1[25], year2[25];
	char *temp;

	for (idx = 0, year1[0] = '\0'; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			strcat(year1, word);
			for (; read_a_utf8_word(raw, word, &idx) == 0;)
			{
				if (isNumber(word) == 1)
				{
					strcat(year1, word);
				}
				else
				{
					break;
				}
			}
			break;
		}
	}
	for (year2[0] = '\0'; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			strcat(year2, word);
			for (; read_a_utf8_word(raw, word, &idx) == 0;)
			{
				if (isNumber(word) == 1)
				{
					strcat(year2, word);
				}
				else
				{
					break;
				}
			}
			break;
		}
	}
	// printf("HERE:%s %s\n", year1, year2);
	csize = utf8_word_length(year2);
	for (i = 0, idx = strlen(year1); i < csize; i++)
	{
		Retreat_a_utf8_word(year1, &idx);
	}
	// printf("HERE:%s %s\n", &year1[idx], year2);
	// printf("HERE:%d %d\n", myatoi(&year1[idx]), myatoi(year2));
	if (myatoi(&year1[idx]) > myatoi(year2))
	{
		strcpy(modify, raw);
		return;
	}

	temp = (char *)malloc((strlen(raw) + 8) * sizeof(char));
	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			strcat(temp, ch_dao);
			strcat(temp, &raw[idx]);
			break;
		}
		else
		{
			strcat(temp, word);
		}
	}
	N2IWND(temp, modify, 1);

	free(temp);
}
void RUOEAO(char *raw, char *modify, int language_code)
{
	int idx;
	char word[7];
	char *temp;

	if (has_dot(raw) == 1)
	{
		for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
		{
			if (isNumber(word) == 1)
			{
				strcat(modify, CH_number[myatoi(word)]);
			}
			else if (isDot(word) == 1)
			{
				strcat(modify, CH_point);
			}
			else if (isEnglish(word) == 1)
			{
				if (strcmp(word, "o") == 0 || strcmp(word, "O") == 0 || strcmp(word, English[66]) == 0 || strcmp(word, English[92]) == 0)
				{
					strcat(modify, CH_number[0]);
				}
			}
			else
			{
				strcat(modify, word);
			}
		}
	}
	else
	{
		temp = (char *)malloc((strlen(raw) + 1) * sizeof(char));
		for (idx = 0, temp[0] = '\0'; read_a_utf8_word(raw, word, &idx) == 0;)
		{
			if (isNumber(word) == 1)
			{
				strcat(temp, word);
			}
			else if (strcmp(word, "o") == 0 || strcmp(word, "O") == 0 || strcmp(word, English[66]) == 0 || strcmp(word, English[92]) == 0)
			{
				strcat(temp, "0");
			}
			else
			{
				STFNVI(temp, &modify[strlen(modify)]);
				strcat(modify, word);
				temp[0]='\0';
			}
		}
		free(temp);
	}
}
void TPEFRU(char *raw, char *modify, int language_code)
{
	char *temp = (char *)malloc((strlen(raw) + 1) * sizeof(char));

	temp[0] = '\0';
	normalize_alphabet_to_ascii(raw, temp, 1);
	// printf("%s %s\n", raw, temp);
	if (strcmp(temp, "?TE") == 0)
	{
		strcat(modify, "why-te");
	}
	else if (strcmp(temp, "R&B") == 0)
	{
		strcat(modify, "R-and-B");
	}
	else if (strcmp(temp, "MAN O\' WAR") == 0)
	{
		strcat(modify, "man-ou-war");
	}
	else if (strcmp(temp, "CO2") == 0)
	{
		strcat(modify, "C-O-two");
	}
	else if (strcmp(temp, "M.2") == 0)
	{
		if (language_code == 1)
		{
			strcat(modify, "M");
			strcat(modify, CH_point);
			strcat(modify, CH_number[2]);
		}
		else
		{
			strcat(modify, "M-dot-two ");
		}
	}
	else if (strcmp(temp, "B.1.621") == 0)
	{
		if (language_code == 1)
		{
			strcat(modify, "B");
			strcat(modify, CH_point);
			strcat(modify, CH_number[1]);
			strcat(modify, CH_point);
			strcat(modify, CH_number[6]);
			strcat(modify, CH_number[2]);
			strcat(modify, CH_number[1]);
		}
		else
		{
			strcat(modify, "B-dot-one-dot-six-two-one ");
		}
	}
	else if (strcmp(temp, "PEER5") == 0)
	{
		strcat(modify, "peer-five");
	}
	else if (strcmp(temp, "AT&T") == 0)
	{
		strcat(modify, "A-T-and-T");
	}
	else if (strcmp(temp, "9M88") == 0)
	{
		strcat(modify, CH_number[9]);
		strcat(modify, "M");
		strcat(modify, CH_number[8]);
		strcat(modify, CH_number[8]);
	}
	else if (strcmp(temp, "3M") == 0)
	{
		strcat(modify, "three M");
	}
	else if (strcmp(temp, "AA+") == 0)
	{
		strcat(modify, "double A plus");
	}
	else if (strcmp(temp, "U2") == 0)
	{
		strcat(modify, "U two ");
	}
	else
	{
		strcat(modify, raw);
	}

	free(temp);
}
void normalize_alphabet_to_ascii(char *raw, char *modify, int capital_flag)
{
	int idx, n_idx;
	char word[7], next[7];

	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		n_idx = idx;
		read_a_utf8_word(raw, next, &n_idx);
		if (isEnglish(word) == 1)
		{
			if (strlen(word) == 3)
			{
				if (word[1] == -68)
				{
					word[0] = word[2] + 160;
				}
				else
				{
					if (capital_flag == 1)
					{
						word[0] = word[2] + 192;
					}
					else
					{
						word[0] = word[2] + 224;
					}
				}
				word[1] = '\0';
				strcat(modify, word);
			}
			else
			{
				if (word[0] >= 97 && capital_flag == 1)
				{
					word[0] -= 32;
				}
				strcat(modify, word);
			}
		}
		else if (isNumber(word) == 1)
		{
			if (strlen(word) == 3)
			{
				strcat(modify, Number[word[2] + 112]);
			}
			else
			{
				strcat(modify, word);
			}
		}
		else if (isspaces(word) == 1 && isspaces(next) == 0)
		{
			strcat(modify, " ");
		}
		else if (isquestion(word) == 1)
		{
			strcat(modify, "?");
		}
		else if (isDot(word) == 1)
		{
			strcat(modify, ".");
		}
		else if (isDash(word) == 1)
		{
			strcat(modify, "-");
		}
		else if (isSlash(word) == 1)
		{
			strcat(modify, "/");
		}
		else if (isNumber_sign(word) == 1)
		{
			strcat(modify, "#");
		}
		else if (isColon(word) == 1)
		{
			strcat(modify, ":");
		}
		else if (isPlus(word) == 1)
		{
			strcat(modify, "+");
		}
		else if (isTilde(word) == 1)
		{
			strcat(modify, "~");
		}
		else if (isapostrophe(word) == 1)
		{
			strcat(modify, "\'");
		}
		else if (isampersand(word) == 1)
		{
			strcat(modify, "&");
		}
		else if (isequal_sign(word) == 1)
		{
			strcat(modify, "=");
		}
		else if (isunder_line(word) == 1)
		{
			strcat(modify, "_");
		}
		else if (isCommercial_At(word) == 1)
		{
			strcat(modify, "@");
		}
		else if (isL_Brackets(word) == 1)
		{
			strcat(modify, "(");
		}
		else if (isR_Brackets(word) == 1)
		{
			strcat(modify, ")");
		}
		else if (strcmp(word, currency_symbols[1]) == 0)
		{
			strcat(modify, "$");
		}
		else
		{
			strcat(modify, word);
		}
	}
}
int myatoi(char *sa)
{
	int ret;
	char *nsa = (char *)malloc((strlen(sa) + 1) * sizeof(char));

	normalize_number(sa, nsa);
	ret = atoi(nsa);

	free(nsa);
	return ret;
}
float myatof(char *sa)
{
	float ret;
	char *nsa = (char *)malloc((strlen(sa) + 1) * sizeof(char));

	normalize_number_float(sa, nsa);
	ret = atof(nsa);

	free(nsa);
	return ret;
}
int roman_num_converter(char *roman_num)
{
	int idx, step;
	int arabic_num, temp_num;

	for (arabic_num = idx = 0; roman_num[idx] != '\0';)
	{
		temp_num = 0;
		if (roman_num[idx] == 'I')
		{
			temp_num = 1;
			step = 1;
			if (roman_num[idx + 1] == 'I')
			{
				temp_num = 2;
				step = 2;
				if (roman_num[idx + 2] == 'I')
				{
					temp_num = 3;
					step = 3;
				}
			}
			else if (roman_num[idx + 1] == 'V')
			{
				temp_num = 4;
				step = 2;
			}
			else if (roman_num[idx + 1] == 'X')
			{
				temp_num = 9;
				step = 2;
			}
		}
		else if (roman_num[idx] == 'V')
		{
			temp_num = 5;
			step = 1;
			if (roman_num[idx + 1] == 'I')
			{
				temp_num = 6;
				step = 2;
				if (roman_num[idx + 2] == 'I')
				{
					temp_num = 7;
					step = 3;
					if (roman_num[idx + 3] == 'I')
					{
						temp_num = 8;
						step = 4;
					}
				}
			}
		}
		else if (roman_num[idx] == 'X')
		{
			temp_num = 10;
			step = 1;
			if (roman_num[idx + 1] == 'X')
			{
				temp_num = 20;
				step = 2;
				if (roman_num[idx + 2] == 'X')
				{
					temp_num = 30;
					step = 3;
				}
			}
			else if (roman_num[idx + 1] == 'L')
			{
				temp_num = 40;
				step = 2;
			}
			else if (roman_num[idx + 1] == 'C')
			{
				temp_num = 90;
				step = 2;
			}
		}
		else if (roman_num[idx] == 'L')
		{
			temp_num = 50;
			step = 1;
			if (roman_num[idx + 1] == 'X')
			{
				temp_num = 60;
				step = 2;
				if (roman_num[idx + 2] == 'X')
				{
					temp_num = 70;
					step = 3;
					if (roman_num[idx + 3] == 'X')
					{
						temp_num = 80;
						step = 4;
					}
				}
			}
		}
		else if (roman_num[idx] == 'C')
		{
			temp_num = 100;
			step = 1;
			if (roman_num[idx + 1] == 'C')
			{
				temp_num = 200;
				step = 2;
				if (roman_num[idx + 2] == 'C')
				{
					temp_num = 300;
					step = 3;
				}
			}
			else if (roman_num[idx + 1] == 'D')
			{
				temp_num = 400;
				step = 2;
			}
			else if (roman_num[idx + 1] == 'M')
			{
				temp_num = 900;
				step = 2;
			}
		}
		else if (roman_num[idx] == 'D')
		{
			temp_num = 500;
			step = 1;
			if (roman_num[idx + 1] == 'C')
			{
				temp_num = 600;
				step = 2;
				if (roman_num[idx + 2] == 'C')
				{
					temp_num = 700;
					step = 3;
					if (roman_num[idx + 3] == 'C')
					{
						temp_num = 800;
						step = 4;
					}
				}
			}
		}
		else if (roman_num[idx] == 'M')
		{
			temp_num = 1000;
			step = 1;
			if (roman_num[idx + 1] == 'M')
			{
				temp_num = 2000;
				step = 2;
				if (roman_num[idx + 2] == 'M')
				{
					temp_num = 3000;
					step = 3;
				}
			}
		}
		arabic_num += temp_num;
		idx += step;
	}
	return arabic_num;
}
void normalize_english_uppercase(char *eng_in, char *eng_out)
{
	int idx;
	char word[7];

	eng_out[0] = '\0';
	for (idx = 0; read_a_utf8_word(eng_in, word, &idx) == 0;)
	{
		if (strlen(word) == 1)
		{
			if (word[0] >= 65 && word[0] <= 90)
			{
				strcat(eng_out, word);
			}
			else if (word[0] >= 97 && word[0] <= 122)
			{
				word[0] -= 32;
				strcat(eng_out, word);
			}
		}
		else if (strlen(word) == 3)
		{
			if (word[0] == -17)
			{
				if (word[1] == -67)
				{
					if (word[2] >= -127 && word[2] <= -102)
					{
						word[0] = word[2] + 192;
						word[1] = '\0';
						strcat(eng_out, word);
					}
				}
				else if (word[1] == -68)
				{
					if (word[2] >= -95 && word[2] <= -70)
					{
						word[0] = word[2] + 160;
						word[1] = '\0';
						strcat(eng_out, word);
					}
				}
			}
		}
	}
}
void pluralize(char *in, char *out)
{
	char *N_in = (char *)malloc((strlen(in) + 1) * sizeof(char));

	normalize_english_uppercase(in, N_in);
	strcpy(out, in);

	if (strfinncmp(N_in, "X", 1) == 0 || strfinncmp(N_in, "Z", 1) == 0 || strfinncmp(N_in, "S", 1) == 0 || strfinncmp(N_in, "SH", 2) == 0 || strfinncmp(N_in, "CH", 2) == 0 || strcmp(N_in, "TOMATO") == 0 || strcmp(N_in, "POTATO") == 0 || strcmp(N_in, "HERO") == 0 || strcmp(N_in, "ECHO") == 0)
	{
		strcat(out, "es");
	}
	else if (strfinncmp(N_in, "FE", 2) == 0)
	{
		strcat(&out[strlen(out) - 2], "ves");
	}
	else if (strfinncmp(N_in, "F", 1) == 0 && strcmp(N_in, "BELIEF") != 0 && strcmp(N_in, "CHIEF") != 0 && strcmp(N_in, "CLIFF") != 0 && strcmp(N_in, "ROOF") != 0)
	{
		strcat(&out[strlen(out) - 1], "ves");
	}
	else if (strfinncmp(N_in, "Y", 1) == 0 && strfinncmp(N_in, "AY", 2) != 0 && strfinncmp(N_in, "EY", 2) != 0 && strfinncmp(N_in, "IY", 2) != 0 && strfinncmp(N_in, "OY", 2) != 0 && strfinncmp(N_in, "UY", 2) != 0)
	{
		strcat(&out[strlen(out) - 1], "ies");
	}
	else
	{
		strcat(out, "s");
	}
	free(N_in);
}
int strfinncmp(char *line1, char *line2, int count)
{
	int i, j, length, ret;
	char *temp1, *temp2;
	if (strlen(line1) > strlen(line2))
	{
		length = strlen(line2);
	}
	else
	{
		length = strlen(line1);
	}
	if (count > length)
	{
		return 0;
	}

	temp1 = (char *)malloc(count * (sizeof(char) + 1));
	temp2 = (char *)malloc(count * (sizeof(char) + 1));

	for (i = strlen(line1) - count, j = 0; i < (int)strlen(line1); i++)
	{
		temp1[j++] = line1[i];
	}
	temp1[j] = '\0';
	for (i = strlen(line2) - count, j = 0; i < (int)strlen(line2); i++)
	{
		temp2[j++] = line2[i];
	}
	temp2[j] = '\0';

	ret = strcmp(temp1, temp2);

	free(temp1);
	free(temp2);

	return ret;
}
void add_day_suffix(char *in, char *out)
{
	int idx, ret;
	char word[7];
	int val = rand() % 2;

	for (idx = 0; read_a_utf8_word(in, word, &idx) == 0;)
	{
		if (is_CH_number(word) == 1 || isNumber(word) == 1)
		{
			strcat(out, week_worship[val]);
			if (is_CH_number(word) == 1)
			{
				strcat(out, word);
			}
			else
			{
				ret = myatoi(word);
				if (ret < 7)
				{
					strcat(out, CH_number[ret]);
				}
				else
				{
					strcat(out, Mandarin_day);
				}
			}
		}
		else
		{
			strcat(out, word);
		}
	}
}
int country_name_idx(char *name)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		if (strcmp(name, country_abbr[i][0]) == 0)
		{
			return i;
		}
	}

	return -1;
}
void RUTMSF(char *raw, char *modify, int language_code)
{
	int idx, flag;
	char word[7];
	char *roman_num = (char *)malloc((strlen(raw) + 1) * sizeof(char));
	char *temp = (char *)malloc((strlen(raw) + 1) * sizeof(char));

	for (idx = 0, flag = 0, temp[0] = '\0'; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isCJK_words(word) == 1)
		{
			if (flag == 1)
			{
				roman_num2arabic_num(roman_num, &temp[strlen(temp)]);
				flag = 0;
			}
			strcat(temp, word);
		}
		else if (flag == 0)
		{
			strcpy(roman_num, word);
			flag = 1;
		}
		else
		{
			strcat(roman_num, word);
		}
	}

	CH_N2SWND(temp, modify, 0);

	free(roman_num);
	free(temp);
}
void N2SWND_FT(char *num_in, char *DPSPW, int language_code)
{
	int i, idx, nidx, dummy_idx, split_num, regist_idx;
	char word[7], nword[7], dummy_word[7];
	char *temp;
	char *unit, *next, *Nnext, *prefix;

	if (language_code == 2)
	{
		NESWND(num_in, DPSPW, language_code);
		return;
	}

	for (idx = split_num = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			split_num++;
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					break;
				}
			}
		}
	}
	// printf("split_num=%d\n", split_num);
	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	/********************************************************************************/
	unit = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	next = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	Nnext = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	prefix = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	for (idx = 0, prefix[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(prefix, word);
		}
		else
		{
			remove_space(prefix);
			break;
		}
	}
	for (idx = strlen(num_in), unit[0] = '\0'; idx != 0;)
	{
		Retreat_a_utf8_word(num_in, &idx);
		read_a_utf8_word(num_in, word, &idx);
		if (isNumber(word) == 1 || isspaces(word) == 1)
		{
			strcpy(unit, &num_in[idx]);
			// printf("%s\n", unit);
			break;
		}
		Retreat_a_utf8_word(num_in, &idx);
	}
	/********************************************************************************/
	for (idx = 0, next[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (strcmp(temp, "2") == 0 || strcmp(temp, Number[12]) == 0)
			{
				/***************************************************************************/
				for (nidx = idx; read_a_utf8_word(num_in, nword, &nidx) == 0;)
				{
					if (isNumber(nword) == 1)
					{
						break;
					}
				}
				if (isNumber(nword) == 1)
				{
					strcpy(next, nword);
					for (; read_a_utf8_word(num_in, nword, &nidx) == 0;)
					{
						if (isNumber(nword) == 1)
						{
							strcat(next, nword);
						}
						else
						{
							break;
						}
					}
				}
				// printf("next=%s\n", next);
				normalize_number(next, Nnext);
				/***************************************************************************/
				dummy_idx = 0;
				read_a_utf8_word(Nnext, dummy_word, &dummy_idx);
				if (strlen(Nnext) == 0 && strcmp(prefix, "第") != 0)
				{
					strcat(temp, unit);
					// printf("%s\n", temp);
					regist_idx = strlen(DPSPW);
					NWMSFW(temp, DPSPW, language_code);
					DPSPW[regist_idx + 3] = '\0';
				}
				else if (strcmp(prefix, "第") == 0 || split_num > 2 ||
						 strcmp(unit, Mandarin_month) == 0 || strcmp(unit, "號") == 0 ||
						 strcmp(unit, Dose) == 0 || strcmp(unit, "樓") == 0 ||
						 strcmp(Nnext, "30") == 0 || strcmp(dummy_word, "3") != 0)
				{
					strcat(DPSPW, CH_number[2]);
				}
				else if ((strcmp(Nnext, "3") != 0 && strcmp(Nnext, CH_number[3]) != 0))
				{
					strcat(DPSPW, CH_number[2]);
				}
				else
				{
					strcat(DPSPW, two_for_measure_word);
				}
			}
			else if (utf8_word_length(temp) == 4 &&
					 ((strncmp(temp, "1", 1) == 0 || strncmp(temp, Number[11], 3) == 0) || (strncmp(temp, "2", 1) == 0 || strncmp(temp, Number[12], 3) == 0)) &&
					 AllisNumber(temp) == 1 &&
					 strncmp(unit, Mandarin_year, strlen(Mandarin_year)) == 0)
			{
				STFNVI(temp, &(DPSPW[strlen(DPSPW)]));
			}
			else
			{
				DPTSFW(temp, &(DPSPW[strlen(DPSPW)]), 1);
			}

			strcat(DPSPW, word);
		}
	}

	free(prefix);
	free(temp);
	free(unit);
	free(next);
	free(Nnext);
}
void TN77SE(char *raw, char *modify, int language_code)
{
	int i, idx;
	char word[7];
	char *temp;

	// if (has_mandarin(raw) == 0)
	//{
	//	strcat(modify, CH_number[7]);
	//	strcat(modify, CH_number[1]);
	//	strcat(modify, CH_number[1]);
	//	return;
	// }
	temp = (char *)malloc((strlen(raw) + 1) * sizeof(char));
	for (idx = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (strcmp(word, "7") != 0 && strcmp(word, Number[17]) != 0)
		{
			if (isNumber(word) == 1)
			{
				strcpy(temp, word);
				for (; read_a_utf8_word(raw, word, &idx) == 0;)
				{
					if (isNumber(word) == 0)
					{
						Retreat_a_utf8_word(raw, &idx);
						break;
					}
					strcat(temp, word);
				}
				N2SSTF(temp, &modify[strlen(modify)], 0);
			}
			else
			{
				strcat(modify, word);
			}
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(raw, word, &idx) == 0;)
			{
				if (strcmp(word, "1") != 0 && strcmp(word, Number[11]) != 0 && isDash(word) == 0)
				{
					// Retreat_a_utf8_word(raw, &idx);
					break;
				}
				strcat(temp, word);
			}
			strcat(modify, "seven-eleven");

			strcat(modify, word);
		}
	}

	free(temp);
}
void FFDFCD(char *raw, char *modify, int language_code)
{
	// MDTSFW(raw, modify);
	int idx = 0, temp_idx, com_idx, size;
	char word[7];
	char *temp = (char *)malloc((strlen(raw) + 1) * sizeof(char));

	for (idx = 0, size = 0; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isSlash(word) == 1)
		{
			size++;
		}
		if (size == 2)
		{
			NTISFW(&(raw[idx]), &(modify[strlen(modify)]), 0);
			strcat(&(modify[strlen(modify)]), Mandarin_year);
			break;
		}
	}
	////////////////////////////////////////////////////////////////////
	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(raw, word, &idx) == 0;)
	{
		if (isSlash(word) == 1)
		{
			break;
		}
		strcat(temp, word);
	}
	for (temp_idx = 0; read_a_utf8_word(temp, word, &temp_idx) == 0;)
	{
		if (isNon_zero_number(word) == 1)
		{
			break;
		}
	}
	Retreat_a_utf8_word(temp, &temp_idx);
	for (com_idx = temp_idx, size = 0; read_a_utf8_word(temp, word, &com_idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			size++;
		}
	}
	if (size > 1)
	{
		NTNSFW(&(temp[temp_idx]), &(modify[strlen(modify)]), 1);
	}
	else
	{
		NTNSFW(&(temp[temp_idx]), &(modify[strlen(modify)]), 0);
	}
	strcat(&(modify[strlen(modify)]), Mandarin_month);
	////////////////////////////////////////////////////////////////////
	strcpy(temp, &(raw[idx]));
	for (temp_idx = 0; read_a_utf8_word(temp, word, &temp_idx) == 0;)
	{
		if (isSlash(word) == 1)
		{
			temp[temp_idx] = '\0';
			break;
		}
	}
	for (temp_idx = 0; read_a_utf8_word(temp, word, &temp_idx) == 0;)
	{
		if (isNon_zero_number(word) == 1)
		{
			break;
		}
	}
	Retreat_a_utf8_word(temp, &temp_idx);
	for (com_idx = temp_idx, size = 0; read_a_utf8_word(temp, word, &com_idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			size++;
		}
	}
	if (size > 1)
	{
		NTNSFW(&(temp[temp_idx]), &(modify[strlen(modify)]), 1);
	}
	else
	{
		NTNSFW(&(temp[temp_idx]), &(modify[strlen(modify)]), 0);
	}
	idx = strlen(raw);
	Retreat_a_utf8_word(raw, &idx);
	read_a_utf8_word(raw, word, &idx);
	// printf("HERE:%s\n",raw);
	strcat(&(modify[strlen(modify)]), retdaynum());

	free(temp);
}
void N2SSTF_LD(char *num_in, char *DPSPW, int language_code)
{
	int i, idx, temp_idx, point_flag = 0, flag = 0;
	char word[7] = "\0", last_word[7] = "\0", temp_word[7] = "\0";
	char *temp;
	char *Nor_num_in = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	Nor_num_in[0] = '\0';
	normalize_alphabet_to_ascii(num_in, Nor_num_in, 1);
	if (strcmp(Nor_num_in, "COVID-19") == 0)
	{
		strcat(DPSPW, "COVID-nineteen ");
		flag = 1;
	}
	else if (strcmp(Nor_num_in, "9TO5") == 0)
	{
		strcat(DPSPW, "nine-to-five ");
		flag = 1;
	}
	else if (strcmp(Nor_num_in, "B2C") == 0)
	{
		strcat(DPSPW, "B-to-C ");
		flag = 1;
	}
	else if (strcmp(Nor_num_in, "B2B") == 0)
	{
		strcat(DPSPW, "B-to-B ");
		flag = 1;
	}
	else if (strcmp(Nor_num_in, "P2P") == 0)
	{
		strcat(DPSPW, "P-to-P ");
		flag = 1;
	}
	else if (strcmp(Nor_num_in, "PCHOME24H") == 0)
	{
		N2SWND(num_in, &(DPSPW[strlen(DPSPW)]), language_code);
		flag = 1;
	}
	if (language_code == 2)
	{
		NEIWND(num_in, DPSPW, language_code);
		flag = 1;
	}
	free(Nor_num_in);
	if (flag == 1)
	{
		return;
	}

	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(DPSPW, word);
			strcpy(last_word, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (has_dot(temp) == 1)
			{
				N2SWND(temp, &(DPSPW[strlen(DPSPW)]), language_code);
			}
			else
			{
				temp_idx = 0;
				read_a_utf8_word(temp, temp_word, &temp_idx);
				if (isEnglish(last_word) == 1 && isEnglish(word) == 0 && utf8_word_length(temp) == 2 && (strcmp(temp_word, "0") != 0 && strcmp(temp_word, "０") != 0))
				{
					N2SWND(temp, &(DPSPW[strlen(DPSPW)]), language_code);
				}
				else
				{
					STFNVI(temp, &(DPSPW[strlen(DPSPW)]));
				}
			}
			strcat(DPSPW, word);
		}
	}

	free(temp);
}
void EDNMNT(char *num_in, char *DPSPW, int language_code)
{
	int i, idx = 0;
	char word[7];
	char *temp;

	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	if (language_code == 1)
	{
		for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isDot(word) == 1)
			{
				strcat(DPSPW, CH_point);
			}
			else if (isNumber(word) == 1)
			{
				NTISFW(word, &(DPSPW[strlen(DPSPW)]), language_code);
			}
			else
			{
				strcat(DPSPW, word);
			}
		}
	}
	else
	{
		for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isDot(word) == 1)
			{
				strcat(DPSPW, "dot-");
			}
			else if (isNumber(word) == 1)
			{
				NEISFW(word, &(DPSPW[strlen(DPSPW)]));
				DPSPW[strlen(DPSPW) - 1] = '-';
			}
			else
			{
				strcat(DPSPW, word);
				strcat(DPSPW, "-");
			}
		}
		DPSPW[strlen(DPSPW) - 1] = ' ';
	}

	free(temp);
}
void NINB4I(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *Ntemp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(DPSPW, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			normalize_number(temp, Ntemp);
			if (strlen(Ntemp) < 4 || has_dot(temp) == 1)
			{
				CH_N2SWND(temp, &(DPSPW[strlen(DPSPW)]), 0);
			}
			else
			{
				NTISFW(temp, &(DPSPW[strlen(DPSPW)]), 0);
			}

			strcat(DPSPW, word);
		}
	}

	free(temp);
	free(Ntemp);
}
void MSTSFW(char *ms, char *sfw, int language_code)
{
	int i;

	for (i = 0; i < 6; i++)
	{
		if (strcmp(ms, mathematical_symbols[i][0]) == 0)
		{
			if (language_code == 1)
			{
				strcpy(sfw, mathematical_symbols[i][1]);
			}
			else
			{
				strcpy(sfw, mathematical_symbols[i][2]);
			}
			return;
		}
	}
	for (i = 0; i < 2; i++)
	{
		if (strcmp(ms, mathematical_symbols_english_only[i][0]) == 0)
		{
			strcpy(sfw, mathematical_symbols_english_only[i][1]);
			return;
		}
	}
	strcpy(sfw, ms);
}
void UAPPUN(char *upu, char *modify, int language_code)
{
	int i, idx, dao_flag = 0;
	char word[7];
	char *token1 = (char *)malloc((strlen(upu) + 1) * sizeof(char));
	char *token2 = (char *)malloc((strlen(upu) + 1) * sizeof(char));
	char interval[7];

	for (idx = 0; read_a_utf8_word(upu, word, &idx) == 0;)
	{
		if (isCJK_words(word) == 1)
		{
			strcat(modify, word);
		}
		else
		{
			if (isDash(word) == 1)
			{
				strcat(modify, ch_negative);
			}
			else if (isPlus(word) == 1)
			{
				strcat(modify, UNIT[12]);
			}
			else
			{
				Retreat_a_utf8_word(upu, &idx);
			}
			break;
		}
	}
	for (token1[0] = '\0'; read_a_utf8_word(upu, word, &idx) == 0;)
	{
		if (isNumber(word) == 1 || isComma(word) == 1 || isDot(word) == 1)
		{
			strcat(token1, word);
		}
		else
		{
			Retreat_a_utf8_word(upu, &idx);
			break;
		}
	}
	for (token2[0] = '\0'; read_a_utf8_word(upu, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1 || isCJK_words(word) == 1)
		{
			dao_flag = 1;
			if (isCJK_words(word) == 1)
			{
				strcpy(interval, word);
			}
			else
			{
				strcpy(interval, ch_dao);
			}
		}
		if (isNumber(word) == 1 || isComma(word) == 1 || isDot(word) == 1)
		{
			strcat(token2, word);
		}
	}

	if (language_code == 1)
	{
		strcat(modify, ch_percent);
		DPTSFW(token1, &modify[strlen(modify)], language_code);
		if (dao_flag == 1)
		{
			strcat(modify, interval);
			strcat(modify, ch_percent);
			DPTSFW(token2, &modify[strlen(modify)], language_code);
		}
	}
	else
	{
		DPTSFW(token1, &modify[strlen(modify)], language_code);
		strcat(modify, "percent ");
		if (dao_flag == 1)
		{
			strcat(modify, "to ");
			DPTSFW(token2, &modify[strlen(modify)], language_code);
			strcat(modify, "percent ");
		}
	}

	free(token1);
	free(token2);
}
void NNLIRW(char *num_in, char *NLNRI, int language_code)
{
	int i, idx;
	char word[7], wdash[7];
	char *token1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *token2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char interval[7];

	for (idx = 0, token1[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1)
		{
			strcpy(wdash, word);
			break;
		}
		strcat(token1, word);
	}
	strcpy(token2, &num_in[idx]);
	// printf("%s %s\n", token1, token2);
	N2SWND(token1, &NLNRI[strlen(NLNRI)], language_code);
	strcat(NLNRI, wdash);
	N2IWND(token2, &NLNRI[strlen(NLNRI)], language_code);

	free(token1);
	free(token2);
}
void NILNRW(char *num_in, char *NLIRN, int language_code)
{
	int i, idx;
	char word[7], wdash[7];
	char *token1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *token2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char interval[7];

	for (idx = 0, token1[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1)
		{
			strcpy(wdash, word);
			break;
		}
		strcat(token1, word);
	}
	strcpy(token2, &num_in[idx]);
	// printf("%s %s\n", token1, token2);
	N2IWND(token1, &NLIRN[strlen(NLIRN)], language_code);
	strcat(NLIRN, wdash);
	N2SWND(token2, &NLIRN[strlen(NLIRN)], language_code);

	free(token1);
	free(token2);
}
void PN2SFW(char *num_in, char *PNABR, int language_code)
{
	int idx;
	char word[7];
	char *numerals = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (strcmp(word, English[15]) != 0 && strcmp(word, English[41]) != 0 &&
			strcmp(word, English[67]) != 0 && strcmp(word, English[93]) != 0)
		{
			strcat(PNABR, word);
		}
		else
		{
			break;
		}
	}
	for (numerals[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1 || isDash(word) == 1 || isTilde(word) == 1)
		{
			strcat(numerals, word);
		}
		else
		{
			continue;
		}
	}
	TODSFW(numerals, &PNABR[strlen(PNABR)], language_code);

	free(numerals);
}
void TODSFW(char *num_in, char *TODCN, int language_code)
{
	int i, idx;
	char word[7];
	char *n1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *n2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0, n1[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isTilde(word) == 0 && isDash(word) == 0)
		{
			strcat(n1, word);
		}
		else
		{
			strcpy(n2, &num_in[idx]);
			break;
		}
	}
	N2SWND(n1, TODCN, language_code);
	if (language_code == 1)
	{
		strcat(TODCN, ch_dao);
	}
	else
	{
		strcat(TODCN, "to ");
	}
	N2SWND(n2, &TODCN[strlen(TODCN)], language_code);

	free(n1);
	free(n2);
}
void MSDWDW(char *num_in, char *MDS, int language_code)
{
	char *tmp1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *tmp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	int idx;
	char word[7];

	for (idx = 0, tmp1[0] = tmp2[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			strcpy(tmp2, &num_in[idx]);
			Retreat_a_utf8_word(num_in, &idx);
			strncpy(tmp1, num_in, idx);
			tmp1[idx] = '\0';
			// printf("%s %s\n",tmp1, tmp2);
			break;
		}
	}

	MDWNDI(tmp1, MDS, language_code);
	strcat(MDS, ch_dao);
	MDWNDI(tmp2, &MDS[strlen(MDS)], language_code);

	free(tmp1);
	free(tmp2);
}
void MDD2YM(char *num_in, char *MDS, int language_code)
{
	char *tmp1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *tmp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	int idx;
	char word[7];

	for (idx = 0, tmp1[0] = tmp2[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			strcpy(tmp2, &num_in[idx]);
			Retreat_a_utf8_word(num_in, &idx);
			strncpy(tmp1, num_in, idx);
			tmp1[idx] = '\0';
			// printf("%s %s\n",tmp1, tmp2);
			break;
		}
	}

	MDWNDI(tmp1, MDS, language_code);
	strcat(MDS, ch_dao);
	YMTSFW(tmp2, &MDS[strlen(MDS)], language_code);

	free(tmp1);
	free(tmp2);
}
int is_CH_number(char *word)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (strcmp(word, CH_number[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
void EANAPN(char *num_in, char *MDS, int language_code)
{
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp[0] = '\0';

	normalize_alphabet_to_ascii(num_in, temp, 1);

	if (strcmp(temp, "A1PLUS") == 0)
	{
		NEIWND(num_in, MDS, language_code);
	}
	else
	{
		CH_N2SWND(num_in, MDS, language_code);
	}

	free(temp);
}
void remove_space(char *line)
{
	int idx;
	char word[7];
	char *tmp = (char *)malloc((strlen(line) + 1) * sizeof(char));

	for (idx = 0, tmp[0] = '\0'; read_a_utf8_word(line, word, &idx) == 0;)
	{
		if (isspaces(word) == 0)
		{
			strcat(tmp, word);
		}
	}
	strcpy(line, tmp);
	free(tmp);
}
void VMPNDN(char *num_in, char *VMP, int language_code)
{
	int idx;
	char word[7];

	VMP[0] = '\0';
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		strcat(VMP, word);
	}

	BNIFRS(&num_in[idx], &VMP[strlen(VMP)], language_code);
}
void BNIFRS(char *num_in, char *NIC, int language_code)
{
	int idx;
	char *temp1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *temp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	temp1[0] = temp2[0] = '\0';

	normalize_alphabet_to_ascii(num_in, temp1, 0);

	for (idx = 0; temp1[idx] != '.' && temp1[idx] != '\0'; idx++)
	{
		temp2[idx] = temp1[idx];
	}
	temp2[idx] = '\0';

	if (language_code == 1)
	{
		NTNSFW(temp2, NIC, 0);
		for (; temp1[idx] != '\0'; idx++)
		{
			if (temp1[idx] == '.')
			{
				strcat(NIC, CH_point);
			}
			else if ((int)temp1[idx] >= 48 && (int)temp1[idx] <= 57)
			{
				strcat(NIC, CH_number[(int)temp1[idx] - 48]);
			}
		}
	}
	else
	{
		NENSFW(temp2, NIC);
		for (; temp1[idx] != '\0'; idx++)
		{
			if (temp1[idx] == '.')
			{
				strcat(NIC, "dot ");
			}
			else if ((int)temp1[idx] >= 48 && (int)temp1[idx] <= 57)
			{
				strcat(NIC, English_number[(int)temp1[idx] - 48]);
				strcat(NIC, " ");
			}
		}
	}

	free(temp1);
	free(temp2);
}
void THCMCS(char *num_in, char *HMS, int language_code)
{
	int idx, i, m, s;
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *Hour = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *Minute = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *Second = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	temp[0] = Hour[0] = Minute[0] = Second[0] = '\0';

	normalize_alphabet_to_ascii(num_in, temp, 0);

	for (idx = i = 0; temp[idx] != ':'; idx++)
	{
		Hour[i++] = temp[idx];
	}
	Hour[i] = '\0';
	for (i = 0, idx++; temp[idx] != ':'; idx++)
	{
		Minute[i++] = temp[idx];
	}
	Minute[i] = '\0';
	strcpy(Second, &temp[idx + 1]);

	// printf("%s %s %s\n", Hour, Minute, Second);
	if (language_code == 1)
	{
		m = myatoi(Minute);
		s = myatoi(Second);
		NTNSFW(Hour, &HMS[strlen(HMS)], 1);
		strcat(&HMS[strlen(HMS)], CH_point);

		if (m > 10)
		{
			NTNSFW(Minute, &HMS[strlen(HMS)], 0);
		}
		else
		{
			strcat(&HMS[strlen(HMS)], CH_number[0]);
			if (m > 0)
			{
				strcat(&HMS[strlen(HMS)], CH_number[m]);
			}
		}
		strcat(&HMS[strlen(HMS)], ch_feng);

		if (s > 10)
		{
			NTNSFW(Second, &HMS[strlen(HMS)], 0);
		}
		else
		{
			strcat(&HMS[strlen(HMS)], CH_number[0]);
			if (s > 0)
			{
				strcat(&HMS[strlen(HMS)], CH_number[s]);
			}
		}
		strcat(&HMS[strlen(HMS)], ch_miao);
	}
	else
	{
		strcpy(HMS, num_in);
	}

	free(temp);
	free(Hour);
	free(Minute);
	free(Second);
}
void UAPPMU(char *upm, char *modify, int language_code)
{
	int i, idx, dao_flag = 0;
	char word[7];
	char *token1 = (char *)malloc((strlen(upm) + 1) * sizeof(char));
	char *token2 = (char *)malloc((strlen(upm) + 1) * sizeof(char));
	char interval[7];

	for (idx = 0; read_a_utf8_word(upm, word, &idx) == 0;)
	{
		if (isCJK_words(word) == 1)
		{
			strcat(modify, word);
		}
		else
		{
			if (isDash(word) == 1)
			{
				strcat(modify, ch_negative);
			}
			else if (isPlus(word) == 1)
			{
				strcat(modify, UNIT[12]);
			}
			else
			{
				Retreat_a_utf8_word(upm, &idx);
			}
			break;
		}
	}
	for (token1[0] = '\0'; read_a_utf8_word(upm, word, &idx) == 0;)
	{
		if (isNumber(word) == 1 || isComma(word) == 1 || isDot(word) == 1)
		{
			strcat(token1, word);
		}
		else
		{
			Retreat_a_utf8_word(upm, &idx);
			break;
		}
	}
	for (token2[0] = '\0'; read_a_utf8_word(upm, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isTilde(word) == 1 || isCJK_words(word) == 1)
		{
			dao_flag = 1;
			if (isCJK_words(word) == 1)
			{
				strcpy(interval, word);
			}
			else
			{
				strcpy(interval, ch_dao);
			}
		}
		if (isNumber(word) == 1 || isComma(word) == 1 || isDot(word) == 1)
		{
			strcat(token2, word);
		}
	}

	if (language_code == 1)
	{
		strcat(modify, ch_per_mill);
		DPTSFW(token1, &modify[strlen(modify)], language_code);
		if (dao_flag == 1)
		{
			strcat(modify, interval);
			strcat(modify, ch_per_mill);
			DPTSFW(token2, &modify[strlen(modify)], language_code);
		}
	}
	else
	{
		DPTSFW(token1, &modify[strlen(modify)], language_code);
		strcat(modify, "per mill ");
		if (dao_flag == 1)
		{
			strcat(modify, "to ");
			DPTSFW(token2, &modify[strlen(modify)], language_code);
			strcat(modify, "per mill ");
		}
	}

	free(token1);
	free(token2);
}
void RSFSTF(char *num_in, char *RAT, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(RAT, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (utf8_word_length(temp) > 3 && has_dot(temp) == 0)
			{
				N2SSTF(temp, &(RAT[strlen(RAT)]), 0);
			}
			else
			{
				CH_N2SWND(temp, &(RAT[strlen(RAT)]), 0);
			}
			if (isColon(word) == 1)
			{
				strcat(RAT, ch_ratio);
			}
			else
			{
				strcat(RAT, word);
			}
		}
	}

	free(temp);
}
void SEMINS(char *num_in, char *SEMI, int language_code)
{
	int i, idx, flag = 0;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *temp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0, temp[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			Retreat_a_utf8_word(num_in, &idx);
			normalize_number(temp, temp2);
			if (strlen(temp2) == 4)
			{
				if (temp2[0] == '2' && temp2[1] == '0')
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				NTNSFW(temp, &(SEMI[strlen(SEMI)]), 1);
			}
			else
			{
				NTISFW(temp, &(SEMI[strlen(SEMI)]), 0);
			}
			strcat(SEMI, &num_in[idx]);
			break;
		}
		strcat(temp, word);
	}

	free(temp);
	free(temp2);
}
void MYSHUT(char *num_in, char *MSU, int language_code)
{
	int i, idx = 0, dao_flag = 0, money_mark = 0;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *temp1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *temp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	temp[0] = '\0';
	normalize_alphabet_to_ascii(num_in, temp, 0);

	if (temp[0] == '$')
	{
		money_mark = 1;
		idx = 1;
	}

	for (temp1[0] = '\0'; read_a_utf8_word(temp, word, &idx) == 0;)
	{
		if (strcmp(word, "/") == 0)
		{
			strcpy(temp2, &temp[idx]);
			Retreat_a_utf8_word(temp, &idx);
			break;
		}
		if (strcmp(word, "-") == 0 || strcmp(word, "~") == 0)
		{
			dao_flag = 1;
		}
		strcat(temp1, word);
	}

	// printf("%s %s\n", temp1, temp2);

	if (dao_flag == 1)
	{
		for (idx = 0; read_a_utf8_word(temp1, word, &idx) == 0;)
		{
			if (strcmp(word, "-") == 0 || strcmp(word, "~") == 0)
			{
				temp1[idx - 1] = '\0';
				N2SWND(temp1, &MSU[strlen(MSU)], 1);
				strcat(MSU, ch_dao);
				N2SWND(&temp1[idx], &MSU[strlen(MSU)], 1);
			}
		}
	}
	else
	{
		N2SWND(temp1, &MSU[strlen(MSU)], 1);
	}

	if (money_mark == 1)
	{
		strcat(MSU, mandarin_money);
	}

	strcat(MSU, "每");

	if (strcmp(temp2, "m2") == 0)
	{
		strcat(MSU, unit_table[0][1]);
	}
	else
	{
		strcat(MSU, temp2);
	}

	free(temp);
	free(temp1);
	free(temp2);
}
void DPWAID(char *num_in, char *DPSPW, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0)
				{
					break;
				}
				strcat(temp, word);
			}
			DPTSFW(temp, &DPSPW[strlen(DPSPW)], language_code);
		}
		if (isDash(word) == 1 || isTilde(word) == 1)
		{
			if (language_code == 1)
			{
				strcat(DPSPW, ch_dao);
			}
			else
			{
				strcat(DPSPW, "to ");
			}
		}
	}

	free(temp);
}
void set_fst(FST *fst)
{
	int i, j, k, input_length_acc, eps_input_acc, non_regular_input_acc, forward_arcs_acc;

	fst->capacity = fst_network_capacity;
	fst->size = fst_network_size;
	fst->num_end = fst_network_num_end;
	fst->num_state = fst_network_num_state;
	fst->end_state = &fst_network_end_state[0];
	fst->aiit.regular_input_size = fst_network_aiit_regular_input_size;
	fst->aiit.max_input_length_size = fst_network_aiit_max_input_length_size;
	fst->aiit.kind_of_regular_input_length = &fst_network_aiit_kind_of_regular_input_length[0];
	fst->aiit.each_regular_input_length_start_idx = &fst_network_aiit_each_regular_input_length_start_idx[0];
	fst->aiit.each_regular_input_length_word_number = &fst_network_aiit_each_regular_input_length_word_number[0];
	fst->aiit.state_regular_input_length = (int **)malloc(fst->num_state * sizeof(int *));
	fst->aiit.eps_input_num = &fst_network_aiit_eps_input_num[0];
	fst->aiit.eps_input_arcs = (int **)malloc(fst->num_state * sizeof(int *));
	fst->aiit.non_regular_input_arc_num = &fst_network_aiit_non_regular_input_arc_num[0];
	fst->aiit.non_regular_input_arcs = (int **)malloc(fst->num_state * sizeof(int *));
	fst->aiit.possible_forward = (unsigned short **)malloc(fst->num_state * sizeof(int *));
	fst->aiit.forward_arcs = (int ***)malloc(fst->num_state * sizeof(int **));
	fst->aiit.regular_inputs = (char **)malloc(fst->aiit.regular_input_size * sizeof(char *));
	fst->arc = (ARC *)malloc(fst->size * sizeof(ARC));

	for (i = input_length_acc = eps_input_acc = non_regular_input_acc = forward_arcs_acc = 0; i < fst->num_state; i++)
	{
		fst->aiit.state_regular_input_length[i] = &fst_network_aiit_state_regular_input_length[input_length_acc];
		input_length_acc += fst->aiit.kind_of_regular_input_length[i];
		fst->aiit.eps_input_arcs[i] = &fst_network_aiit_eps_input_arcs[eps_input_acc];
		eps_input_acc += fst->aiit.eps_input_num[i];
		fst->aiit.non_regular_input_arcs[i] = &fst_network_aiit_non_regular_input_arcs[non_regular_input_acc];
		non_regular_input_acc += fst->aiit.non_regular_input_arc_num[i];
		fst->aiit.possible_forward[i] = fst_network_aiit_possible_forward[i];
		fst->aiit.forward_arcs[i] = (int **)malloc(fst->aiit.regular_input_size * sizeof(int *));
		for (j = 0; j < fst->aiit.regular_input_size; j++)
		{
			// fst->aiit.forward_arcs[i][j] = (int *)malloc((fst->aiit.possible_forward[i][j] + 1) * sizeof(int));
			// for (k = 0; k < fst->aiit.possible_forward[i][j]; k++)
			//{
			//	fst->aiit.forward_arcs[i][j][k] = fst_network_aiit_forward_arcs[forward_arcs_acc + k];
			// }
			if (fst->aiit.possible_forward[i][j] != 0)
			{
				fst->aiit.forward_arcs[i][j] = &fst_network_aiit_forward_arcs[forward_arcs_acc][0];
				forward_arcs_acc++;
			}
			// fst->aiit.forward_arcs[i][j] = &fst_network_aiit_forward_arcs[forward_arcs_acc];
			// forward_arcs_acc += fst->aiit.possible_forward[i][j];
		}
	}

	for (i = 0; i < fst->aiit.regular_input_size; i++)
	{
		fst->aiit.regular_inputs[i] = fst_network_aiit_regular_inputs[i];
	}

	for (i = 0; i < fst->size; i++)
	{
		fst->arc[i].istate = fst_network_arcs_state[i][0];
		fst->arc[i].ostate = fst_network_arcs_state[i][1];
		fst->arc[i].itemp = fst_network_arcs_io[i][0];
		fst->arc[i].otemp = fst_network_arcs_io[i][1];
	}
}
void YMOMDT(char *num_in, char *modify, int language_code)
{
	int i, idx;
	char word[7];
	char *temp;

	if (language_code == 2)
	{
		NESWND(num_in, modify, language_code);
		return;
	}
	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			strcat(modify, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (strcmp(word, Mandarin_year) == 0)
			{
				NTISFW(temp, &(modify[strlen(modify)]), language_code);
			}
			else
			{
				DPTSFW(temp, &(modify[strlen(modify)]), 1);
			}
			strcat(modify, word);
		}
	}

	free(temp);
}
void N2SCAC(char *num_in, char *modify, int language_code)
{
	int i, idx, colon_idx;
	char word[7];
	char *temp;

	if (language_code == 2)
	{
		NESWND(num_in, modify, language_code);
		return;
	}
	temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			if (isTilde(word) == 1 || isDash(word) == 1)
			{
				strcat(modify, "到");
			}
			else
			{
				strcat(modify, word);
			}
		}
		else
		{
			strcpy(temp, word);
			for (colon_idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isColon(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
				if (isColon(word) == 1)
				{
					colon_idx = strlen(temp);
					Retreat_a_utf8_word(temp, &colon_idx);
					strcat(modify, "第");
					temp[colon_idx] = '\0';
					N2SWND(temp, &modify[strlen(modify)], 1);
					strcat(modify, "章");
					temp[0] = '\0';
				}
			}
			strcat(modify, "第");
			N2SWND(temp, &modify[strlen(modify)], 1);
			if (strcmp(word, "節") != 0)
			{
				strcat(modify, "節");
				if (isTilde(word) == 1 || isDash(word) == 1)
				{
					strcat(modify, "到");
				}
				else
				{
					strcat(modify, word);
				}
			}
			else
			{
				strcat(modify, word);
			}
		}
	}

	free(temp);
}
int is_utf8_string(char *line)
{
	int index = strlen(line);

	while (index > 0)
	{
		if (index < 0)
		{
			return 0;
		}
		if (line[index - 1] > 0)
		{
			(index) -= 1;
		}
		else if (line[index - 2] >= -64 && line[index - 2] <= -33)
		{
			if(line[index - 1] > -65)
			{
				return 0;
			}
			(index) -= 2;
		}
		else if (line[index - 3] >= -32 && line[index - 3] <= -17)
		{
			if(line[index - 2] > -65 || line[index - 1] > -65)
			{
				return 0;
			}
			(index) -= 3;
		}
		else if (line[index - 4] >= -16 && line[index - 4] <= -9)
		{
			if(line[index - 3] > -65 || line[index - 2] > -65 || line[index - 1] > -65)
			{
				return 0;
			}
			(index) -= 4;
		}
		else if (line[index - 5] >= -8 && line[index - 5] <= -5)
		{
			if(line[index - 4] > -65 || line[index - 3] > -65 || line[index - 2] > -65 || line[index - 1] > -65)
			{
				return 0;
			}
			(index) -= 5;
		}
		else if (line[index - 6] >= -4 && line[index - 6] <= -3)
		{
			if(line[index - 5] > -65 || line[index - 4] > -65 || line[index - 3] > -65 || line[index - 2] > -65 || line[index - 1] > -65)
			{
				return 0;
			}
			index -= 6;
		}
		else
		{
			return 0;
		}
	}

	return 1;
}
void MASAFW(char *num_in, char *modify, int language_code)
{
	char *angle = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *minute = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *second = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	int idx;
	char word[7];

	angle[0] = minute[0] = second[0] = '\0';

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		strcat(modify, word);
	}
	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0)
		{
			break;
		}
		strcat(angle, word);
	}
	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isspaces(word) == 1)
		{
			continue;
		}
		if (isNumber(word) == 0 && isDot(word) == 0)
		{
			break;
		}
		strcat(minute, word);
	}
	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isspaces(word) == 1)
		{
			continue;
		}
		if (isNumber(word) == 0 && isDot(word) == 0)
		{
			break;
		}
		strcat(second, word);
	}

	// printf("%s %s %s\n", angle, minute, second);

	if (language_code == 1)
	{
		N2SWND(angle, &modify[strlen(modify)], 1);
		strcat(modify, "度");
		if (strlen(minute) > 0)
		{
			N2SWND(minute, &modify[strlen(modify)], 1);
			strcat(modify, "分");
		}
		if (strlen(second) > 0)
		{
			N2SWND(second, &modify[strlen(modify)], 1);
			strcat(modify, "秒");
		}
	}
	else
	{
		NESWND(angle, &modify[strlen(modify)], language_code);
		strcat(modify, "degrees ");
		if (strlen(minute) > 0)
		{
			NESWND(minute, &modify[strlen(modify)], language_code);
			strcat(modify, "minutes ");
		}
		if (strlen(second) > 0)
		{
			NESWND(second, &modify[strlen(modify)], language_code);
			strcat(modify, "seconds ");
		}
	}
	// if(){}

	free(angle);
	free(minute);
	free(second);
}
void EAWWON(char *num_in, char *modify, int language_code)
{
	char *prefix = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *nor_prefix = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *pure_num = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char word[7];
	int idx;

	prefix[0] = nor_prefix[0] = pure_num[0] = '\0';

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		strcat(prefix, word);
	}
	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0)
		{
			break;
		}
		strcat(pure_num, word);
	}

	normalize_alphabet_to_ascii(prefix, nor_prefix, 1);
	// printf("%s\n", nor_prefix);
	if (strcmp(nor_prefix, "NO.") == 0)
	{
		strcat(&modify[strlen(modify)], "Number ");
	}
	else if (strcmp(nor_prefix, "VOL.") == 0)
	{
		strcat(&modify[strlen(modify)], "Volume ");
	}
	else
	{
		strcat(&modify[strlen(modify)], prefix);
		strcat(&modify[strlen(modify)], " ");
	}

	NENSFW(pure_num, &modify[strlen(modify)]);

	free(prefix);
	free(nor_prefix);
	free(pure_num);
}
void CFTSFW(char *cf, char *modify, int language_code)
{
	// char *antecedent_term = (char *)malloc((strlen(cf) + 1) * sizeof(char));
	// char *consequent_term = (char *)malloc((strlen(cf) + 1) * sizeof(char));
	char *cf1 = (char *)malloc((strlen(cf) + 1) * 16 * sizeof(char));
	int idx;
	char word[7], last[7];

	// antecedent_term[0] = consequent_term[0] = '\0';
	cf1[0] = '\0';

	N2SWND(cf, cf1, 1);
	// printf("%s\n", cf1);
	for (idx = 0; read_a_utf8_word(cf1, word, &idx) == 0;)
	{
		if (isDash(word) == 1)
		{
			strcat(modify, "負");
		}
		else if (isPlus(word) == 1)
		{
			if (isEnglish(last) == 1)
			{
				strcat(modify, "正");
			}
			else
			{
				strcat(modify, "加");
			}
		}
		else
		{
			strcat(modify, word);
		}
		strcpy(last, word);
	}

	// free(antecedent_term);
	// free(consequent_term);
	free(cf1);
}
void RWAPAS(char *rw, char *modify, int language_code)
{
	char *p_term = (char *)malloc((strlen(rw) + 1) * sizeof(char));
	char *s_term = (char *)malloc((strlen(rw) + 1) * sizeof(char));
	char word[7], mid_term[7];
	int idx, pn, sn, dao_flag = 0;

	p_term[0] = s_term[0] = '\0';

	for (idx = 0; read_a_utf8_word(rw, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			if (isDash(word) == 1)
			{
				strcpy(mid_term, word);
			}
			break;
		}
		strcat(p_term, word);
	}
	for (; read_a_utf8_word(rw, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(rw, &idx);
			break;
		}
		if (isDash(word) == 1)
		{
			strcpy(mid_term, word);
		}
	}
	strcpy(s_term, &rw[idx]);

	pn = myatoi(p_term);
	sn = myatoi(s_term);

	// printf("%s %s %s %d %d\n", p_term, s_term, mid_term, pn, sn);

	if (sn > pn)
	{
		if (strlen(p_term) == 3)
		{
			if (sn - pn < 10)
			{
				dao_flag = 1;
			}
		}
		else if (strlen(p_term) == 4)
		{
			if (sn - pn < 100)
			{
				dao_flag = 1;
			}
		}
		else if (strlen(p_term) == 5)
		{
			if (sn - pn < 1000)
			{
				dao_flag = 1;
			}
		}
	}

	if (language_code == 1)
	{
		N2IWND(p_term, &modify[strlen(modify)], 1);
		if (dao_flag == 1)
		{
			strcat(modify, "到");
		}
		else
		{
			strcat(modify, mid_term);
		}
		N2IWND(s_term, &modify[strlen(modify)], 1);
	}
	else
	{
		NESWND(p_term, &modify[strlen(modify)], language_code);
		if (dao_flag == 1)
		{
			strcat(modify, "to ");
		}
		else
		{
			strcat(modify, mid_term);
		}
		NESWND(s_term, &modify[strlen(modify)], language_code);
	}

	free(p_term);
	free(s_term);
}
void RWPOST(char *rw, char *modify, int language_code)
{
	char *prefix[2];
	char *nor_prefix = (char *)malloc((strlen(rw) + 1) * sizeof(char));
	char *p_term = (char *)malloc((strlen(rw) + 1) * sizeof(char));
	char *s_term = (char *)malloc((strlen(rw) + 1) * sizeof(char));
	char word[7], mid_term[7];
	int idx;

	prefix[0] = (char *)malloc((strlen(rw) + 1) * sizeof(char));
	prefix[1] = (char *)malloc((strlen(rw) + 1) * sizeof(char));
	prefix[0][0] = prefix[1][0] = nor_prefix[0] = p_term[0] = s_term[0] = '\0';

	for (idx = 0; read_a_utf8_word(rw, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(rw, &idx);
			break;
		}
		else if (isspaces(word) == 0)
		{
			strcat(prefix[0], word);
		}
	}
	for (; read_a_utf8_word(rw, word, &idx) == 0;)
	{
		if (isNumber(word) == 0)
		{
			if (isspaces(word) == 0)
			{
				strcpy(mid_term, word);
			}
			break;
		}
		strcat(p_term, word);
	}
	for (; read_a_utf8_word(rw, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(rw, &idx);
			break;
		}
		if (isspaces(word) == 0)
		{
			if (isDash(word) == 1 || isTilde(word) == 1)
			{
				strcpy(mid_term, word);
			}
			else
			{
				strcat(prefix[1], word);
			}
		}
	}
	strcpy(s_term, &rw[idx]);

	// printf("%s %s %s %s %s\n", prefix[0], p_term, mid_term, prefix[1], s_term);
	normalize_alphabet_to_ascii(prefix[0], nor_prefix, 1);

	if (language_code == 1)
	{
		if (strncmp(nor_prefix, "PP", 2) != 0)
		{
			strcat(modify, prefix[0]);
		}
		N2SWND(p_term, &modify[strlen(modify)], 1);
		strcat(modify, "到");
		if (strncmp(nor_prefix, "PP", 2) != 0)
		{
			strcat(modify, prefix[1]);
		}
		N2SWND(s_term, &modify[strlen(modify)], 1);
		if (strncmp(nor_prefix, "PP", 2) == 0)
		{
			strcat(modify, "頁");
		}
	}
	else
	{
		if (strncmp(nor_prefix, "PP", 2) == 0)
		{
			strcat(modify, "Pages ");
		}
		else
		{
			strcat(modify, prefix[0]);
			strcat(modify, " ");
		}
		NESWND(p_term, &modify[strlen(modify)], language_code);
		strcat(modify, "to ");
		if (strncmp(nor_prefix, "PP", 2) == 0)
		{
			strcat(modify, "Pages ");
		}
		else
		{
			strcat(modify, prefix[0]);
			strcat(modify, " ");
		}
		NESWND(s_term, &modify[strlen(modify)], language_code);
	}

	free(prefix[0]);
	free(prefix[1]);
	free(nor_prefix);
	free(p_term);
	free(s_term);
}
void CRTSFW(char *cr, char *modify, int language_code)
{
	char *min_term = (char *)malloc((strlen(cr) + 1) * sizeof(char));
	char *sec_term = (char *)malloc((strlen(cr) + 1) * sizeof(char));
	char *diff_term = (char *)malloc((strlen(cr) + 1) * sizeof(char));
	char word[7];
	int idx;

	min_term[0] = sec_term[0] = diff_term[0] = '\0';

	for (idx = 0; read_a_utf8_word(cr, word, &idx) == 0;)
	{
		if (isColon(word) == 1)
		{
			break;
		}
		strcat(min_term, word);
	}
	for (; read_a_utf8_word(cr, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0)
		{
			break;
		}
		strcat(sec_term, word);
	}
	for (; read_a_utf8_word(cr, word, &idx) == 0;)
	{
		if (isNumber(word) == 1 || isDot(word) == 1)
		{
			strcat(diff_term, word);
		}
	}

	// printf("%s %s %s\n", min_term, sec_term, diff_term);

	if (language_code == 1)
	{
		if(strcmp(min_term, "2") == 0 || strcmp(min_term, "２") == 0)
		{
			strcat(modify, "兩");
		}
		else
		{
			N2SWND(min_term, &modify[strlen(modify)], 1);
		}
		strcat(modify, "分");
		N2SWND(sec_term, &modify[strlen(modify)], 1);
		strcat(modify, "秒");
		if (strlen(diff_term) > 0)
		{
			strcat(modify, " 差");
			N2SWND(diff_term, &modify[strlen(modify)], 1);
		}
	}
	else
	{
		N2SWND(min_term, &modify[strlen(modify)], 2);
		strcat(modify, "minutes and ");
		N2SWND(sec_term, &modify[strlen(modify)], 2);
		strcat(modify, "seconds ");
		if (strlen(diff_term) > 0)
		{
			strcat(modify, "diff ");
			N2SWND(diff_term, &modify[strlen(modify)], 2);
		}
	}

	free(min_term);
	free(sec_term);
	free(diff_term);
}
void LATEXT(char *latex, char *modify, int language_code)
{
	int i, idx, tok_capacity = 5, tok_size;
	char *tok[1024], word[7];

	for (i = 0; i < tok_capacity; i++)
	{
		tok[i] = (char *)malloc((strlen(latex) + 1) * sizeof(char));
		tok[i][0] = '\0';
	}

	for (tok_size = idx = 0; read_a_utf8_word(latex, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0)
		{
			if (strcmp(word, "{") == 0 || strcmp(word, "}") == 0 || isspaces(word) == 1)
			{
				if (strlen(tok[tok_size]) > 0)
				{
					tok_size++;
				}
			}
			else if (strlen(tok[tok_size]) == 0)
			{
				strcpy(tok[tok_size++], word);
			}
			else
			{
				strcpy(tok[++tok_size], word);
				tok_size++;
			}
		}
		else
		{
			strcat(tok[tok_size], word);
		}
	}

	//	printf("%d ", tok_size);
	//	for (i = 0; i < tok_size; i++)
	//	{
	//		printf("%s ", tok[i]);
	//	}
	//	printf("\n");

	for (i = 0; i < tok_size; i++)
	{
		if (isDash(tok[i]) == 1)
		{
			if (i == 0)
			{
				strcat(modify, "負");
			}
			else if (has_number(tok[i - 1]) == 1)
			{
				strcat(modify, "減");
			}
			else
			{
				strcat(modify, "負");
			}
		}
		else if (tok[i][0] == '^')
		{
			strcat(modify, "的");
			for (i = i + 1;; i++)
			{
				if (isDash(tok[i]) == 1)
				{
					strcat(modify, "負");
				}
				else
				{
					N2SWND(tok[i], &modify[strlen(modify)], 1);
				}
				if (has_number(tok[i]) == 1)
				{
					break;
				}
			}
			strcat(modify, "次方");
		}
		else
		{
			N2SWND(tok[i], &modify[strlen(modify)], 1);
		}
	}

	for (i = 0; i < tok_capacity; i++)
	{
		free(tok[i]);
	}
}
void HSAESF(char *hsae, char *modify, int language_code)
{
	char *item1 = (char *)malloc((strlen(hsae) + 1) * sizeof(char));
	char *item2 = (char *)malloc((strlen(hsae) + 1) * sizeof(char));
	char word[7];
	int idx;

	for (idx = 0, item1[0] = '\0'; read_a_utf8_word(hsae, word, &idx) == 0;)
	{
		if (isspaces(word) == 0 && word[0] != '^')
		{
			strcat(item1, word);
		}
		else if (word[0] == '^')
		{
			break;
		}
	}

	for (; read_a_utf8_word(hsae, word, &idx) == 0;)
	{
		if (isspaces(word) == 0)
		{
			Retreat_a_utf8_word(hsae, &idx);
			strcpy(item2, &hsae[idx]);
			break;
		}
	}

	// printf("%s %s\n",item1,item2);
	idx = 0;
	read_a_utf8_word(item1, word, &idx);
	if (isDash(word) == 1)
	{
		strcat(modify, "負");
		N2SWND(&item1[strlen(word)], &modify[strlen(modify)], 1);
	}
	else
	{
		N2SWND(item1, &modify[strlen(modify)], 1);
	}
	strcat(modify, "的");
	if (strcmp(item2, "2") == 0 || strcmp(item2, "２") == 0)
	{
		strcat(modify, "平方");
	}
	else
	{
		idx = 0;
		read_a_utf8_word(item2, word, &idx);
		if (isDash(word) == 1)
		{
			strcat(modify, "負");
			N2SWND(&item2[strlen(word)], &modify[strlen(modify)], 1);
		}
		else
		{
			N2SWND(item2, &modify[strlen(modify)], 1);
		}
		strcat(modify, "次方");
	}

	free(item1);
	free(item2);
}
void DAFROL(char *num_in, char *modify, int language_code)
{
	char *item1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *item2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char word[7];
	int idx;

	// printf("%s\n", num_in);
	for (idx = 0, item1[0] = item2[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			strcat(item1, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isDash(word) == 1)
				{
					for (; read_a_utf8_word(num_in, word, &idx) == 0;)
					{
						if (isNumber(word) == 0)
						{
							Retreat_a_utf8_word(num_in, &idx);
							break;
						}
						strcat(item2, word);
					}
					break;
				}
				strcat(item1, word);
			}
			break;
		}
		else
		{
			strcat(modify, word);
		}
	}
	if (utf8_word_length(item1) == 1)
	{
		NTISFW(item1, &modify[strlen(modify)], 0);
	}
	else if (utf8_word_length(item1) <= 3)
	{
		NTNSFW(item1, &modify[strlen(modify)], 0);
	}
	else
	{
		STFNVI(item1, &modify[strlen(modify)]);
	}
	strcat(modify, "之");
	if (utf8_word_length(item2) == 1)
	{
		NTISFW(item2, &modify[strlen(modify)], 0);
	}
	else
	{
		NTNSFW(item2, &modify[strlen(modify)], 0);
	}
	strcat(modify, &num_in[idx]);

	free(item1);
	free(item2);
}
void MDHMTO(char *num_in, char *modify, int language_code)
{
	char *item = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	int idx;
	char word[7];

	// printf("%s\n", num_in);

	for (idx = 0, item[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isspaces(word) == 1)
		{
			break;
		}
		strcat(item, word);
		if (strcmp(word, "日") == 0)
		{
			break;
		}
	}
	// printf("%s\n", item);
	N2SWND(item, &modify[strlen(modify)], 1);

	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
	}

	for (item[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isDash(word) == 1 || isspaces(word) == 1)
		{
			break;
		}
		strcat(item, word);
	}
	// printf("%s\n", item);
	HMTSFW(item, &modify[strlen(modify)], 0);

	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
	}
	strcat(modify, "到");

	for (item[0] = '\0'; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isspaces(word) == 1)
		{
			break;
		}
		strcat(item, word);
		if (strcmp(word, "日") == 0)
		{
			break;
		}
	}
	// printf("%s\n", item);
	N2SWND(item, &modify[strlen(modify)], 1);

	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
	}

	// printf("%s\n", &num_in[idx]);
	HMTSFW(&num_in[idx], &modify[strlen(modify)], 0);

	free(item);
}
void NFNLT4(char *num_in, char *modify, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(modify, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (utf8_word_length(temp) > 3)
			{
				STFNVI(temp, &(modify[strlen(modify)]));
			}
			else
			{
				DPTSFW(temp, &(modify[strlen(modify)]), 1);
			}
			strcat(modify, word);
		}
	}

	free(temp);
}
void THMSSF(char *num_in, char *HMS, int language_code)
{
	int idx, i, m, s;
	char word[7];
	char *Minute = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *Second = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	Minute[0] = Second[0] = '\0';

	if (language_code == 1)
	{
		for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
		{
			if (isNumber(word) == 1)
			{
				strcpy(Minute, word);
				for (; read_a_utf8_word(num_in, word, &idx) == 0;)
				{
					if (isColon(word) == 1)
					{
						strcat(Minute, "分");
						NWMSFW(Minute, &HMS[strlen(HMS)], language_code);
						for (; read_a_utf8_word(num_in, word, &idx) == 0;)
						{
							if (isNumber(word) == 0)
							{
								break;
							}
							strcat(Second, word);
						}
						if (myatoi(Second) < 10)
						{
							NTISFW(Second, &HMS[strlen(HMS)], language_code);
							strcat(HMS, "秒");
						}
						else
						{
							strcat(Second, "秒");
							NWMSFW(Second, &HMS[strlen(HMS)], language_code);
						}
						if (isNumber(word) == 0)
						{
							Retreat_a_utf8_word(num_in, &idx);
							strcat(HMS, &num_in[idx]);
						}
						break;
					}
					strcat(Minute, word);
				}
				break;
			}
			strcat(HMS, word);
		}
	}
	else
	{
		strcpy(HMS, num_in);
	}

	free(Minute);
	free(Second);
}
void NFSNFS(char *num_in, char *modify, int language_code)
{
	int i, idx;
	float v1, v2;
	char word[7], middle_dash[7];
	char *temp1 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));
	char *temp2 = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	// printf("%s\n", num_in);
	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(modify, word);
		}
		else
		{
			strcpy(temp1, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					if (isDash(word) == 1)
					{
						strcpy(middle_dash, word);
					}
					break;
				}
				strcat(temp1, word);
			}
			break;
		}
	}
	// printf("%s\n", temp1);
	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 1)
		{
			strcpy(temp2, word);
			break;
		}
		if (isDash(word) == 1)
		{
			strcpy(middle_dash, word);
		}
	}
	for (; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			Retreat_a_utf8_word(num_in, &idx);
			break;
		}
		strcat(temp2, word);
	}

	v1 = myatof(temp1);
	v2 = myatof(temp2);
	// printf("%s %s %d %d\n", temp1, temp2, v1, v2);
	if (v1 == 737 || v1 == 747 || v1 == 767 || v1 == 777 || v1 == 787)
	{
		STFNVI(temp1, &modify[strlen(modify)]);
		strcat(modify, middle_dash);
		STFNVI(temp2, &modify[strlen(modify)]);
		strcat(modify, &num_in[idx]);
	}
	else if(v1 == 7 && v2 == 11)
	{
		strcat(modify, "七");
		strcat(modify, middle_dash);
		strcat(modify, "一一");
		strcat(modify, &num_in[idx]);
	}
	else
	{
		N2SWND(temp1, &modify[strlen(modify)], language_code);
		if (v2 > v1)
		{
			if(v2-v1<100)
			{
				if (language_code == 1)
				{
					strcat(modify, "到");
				}
				else
				{
					strcat(modify, " to ");
				}
			}
			else
			{
				strcat(modify, middle_dash);
			}
		}
		else
		{
			if(has_dot(temp1)==1 || has_dot(temp2)==1  || has_comma(temp2)==1  || has_comma(temp2)==1 )
			{
				if (language_code == 1)
				{
					strcat(modify, "減");
				}
				else
				{
					strcat(modify, " minus ");
				}
			}
			else
			{
				strcat(modify, middle_dash);
			}
		}
		N2SWND(temp2, &modify[strlen(modify)], language_code);
		strcat(modify, &num_in[idx]);
	}

	free(temp1);
	free(temp2);
}
void NFNLT3(char *num_in, char *modify, int language_code)
{
	int i, idx;
	char word[7];
	char *temp = (char *)malloc((strlen(num_in) + 1) * sizeof(char));

	for (idx = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
		{
			strcat(modify, word);
		}
		else
		{
			strcpy(temp, word);
			for (; read_a_utf8_word(num_in, word, &idx) == 0;)
			{
				if (isNumber(word) == 0 && isDot(word) == 0 && isComma(word) == 0)
				{
					// Retreat_a_utf8_word(num_in, &idx);
					break;
				}
				strcat(temp, word);
			}
			if (utf8_word_length(temp) > 2)
			{
				STFNVI(temp, &(modify[strlen(modify)]));
			}
			else
			{
				DPTSFW(temp, &(modify[strlen(modify)]), 1);
			}
			strcat(modify, word);
		}
	}

	free(temp);
}
void NUDLOP(char *num_in, char *modify, int language_code)
{
	char **temp, word[7];
	float *temp_value;
	int idx, i, dash_num;

	for(idx = 0, dash_num = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if(isDash(word) == 1)
		{
			dash_num++;
		}
	}
	temp = (char**)malloc((dash_num + 1) * sizeof(char*));
	temp_value = (float*)malloc((dash_num + 1) * sizeof(float));;
	for(i = 0; i <= dash_num; i++)
	{
		temp[i] = (char*)malloc((strlen(num_in) + 1) * sizeof(char));
		temp[i][0] = '\0';
	}

	for(idx = 0, i = 0; read_a_utf8_word(num_in, word, &idx) == 0;)
	{
		if(isDash(word) == 1)
		{
			i++;
			continue;
		}
		strcat(temp[i], word);
	}

	for(i = 0; i <= dash_num; i++)
	{
		temp_value[i] = myatof(temp[i]);
	}

	if(dash_num == 1)
	{
		N2SWND(temp[0], &modify[strlen(modify)], 1);
		if(temp_value[0] > temp_value[1])
		{
			strcat(modify,"減");
		}
		else
		{
			strcat(modify,"到");
		}
		N2SWND(temp[1], &modify[strlen(modify)], 1);
	}
	else
	{
		N2SWND(temp[0], &modify[strlen(modify)], 1);
		for(i = 0 ;i < dash_num; i++)
		{
			strcat(modify,"減");
			N2SWND(temp[i + 1], &modify[strlen(modify)], 1);
		}
	}

	for(i = 0; i <= dash_num; i++)
	{
		free(temp[i]);
	}
	free(temp);
	free(temp_value);
}
void CNWAAN(char *num_in, char *modify, int language_code)
{
	char *temp = malloc((strlen(num_in) + 1) * sizeof(char));

	temp[0] = '\0';
	if (ch_numerals_to_ar_numerals(num_in, temp))
	{
		N2SWND(temp, modify, 1);
	}
	else
	{
		STFNVI(temp, modify);
	}

	free(temp);
}
int ch_numerals_to_ar_numerals(char *in, char *out)
{
	int i, idx, has_non_CH_numerals_input = 0;
	char word[7];

	for (idx = 0; read_a_utf8_word(in, word, &idx) == 0;)
	{
		for (i = 1; i < 10; i++)
		{
			if (strcmp(word, CH_number[i]) == 0)
			{
				break;
			}
		}
		if (i < 10)
		{
			strcat(out, Number[i]);
		}
		else
		{
			if (strcmp(word, "〇") == 0 || strcmp(word, "○") == 0)
			{
				strcat(out, Number[0]);
			}
			else
			{
				strcat(out, word);
				has_non_CH_numerals_input = 1;
			}
		}
	}

	return has_non_CH_numerals_input;
}
void wrap_strcpy(char *t, char *s, int dummy){
	strcpy(s,t);
}