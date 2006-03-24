#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NCYCLES 4096

int sizes[NCYCLES] = {
  11986,
  277806,
  2659,
  46,
  0,
  775553,
  1991,
  21,
  7638,
  250197,
  155828,
  5777,
  9,
  315006,
  900788,
  0,
  24893,
  119996,
  72299,
  171266,
  357,
  560,
  368,
  22952,
  54058,
  12638,
  39155,
  2738,
  217563,
  26853,
  47,
  75,
  1167,
  16917,
  1899,
  2905,
  9337,
  62243,
  14214,
  270523,
  4024,
  21,
  32,
  14892,
  625144,
  13,
  21700,
  8804,
  254147,
  0,
  6,
  836004,
  1718,
  2289,
  15554,
  412857,
  185097,
  806709,
  64,
  18602,
  17064,
  1779,
  78153,
  170600,
  199100,
  546528,
  0,
  21,
  20609,
  16514,
  548196,
  311446,
  53484,
  0,
  551,
  22225,
  24,
  153989,
  457309,
  526833,
  227979,
  757167,
  429560,
  0,
  835,
  1702,
  475275,
  798416,
  753,
  0,
  11126,
  145779,
  2006,
  0,
  8182,
  0,
  569432,
  9671,
  36,
  5523,
  407325,
  0,
  65,
  9293,
  0,
  6793,
  468701,
  73,
  0,
  186236,
  0,
  328405,
  125616,
  508013,
  380519,
  599518,
  83,
  151973,
  466906,
  9029,
  159725,
  1316,
  1,
  911532,
  1508,
  19050,
  972850,
  126,
  439377,
  29,
  37928,
  149628,
  54,
  130248,
  2,
  143,
  0,
  716873,
  3327,
  5,
  116131,
  5124,
  559621,
  2886,
  534,
  186432,
  441,
  7348,
  10331,
  1,
  260935,
  7,
  4370,
  405415,
  2,
  84518,
  1970,
  1,
  281910,
  46,
  274,
  2273,
  370565,
  4190,
  820641,
  577970,
  32809,
  974893,
  398067,
  380698,
  4,
  25978,
  153,
  882668,
  312365,
  9523,
  156421,
  0,
  268143,
  6,
  2,
  42987,
  212,
  12303,
  6723,
  1179,
  0,
  120924,
  3877,
  330421,
  310445,
  39264,
  8,
  85380,
  464716,
  0,
  33657,
  6285,
  0,
  4491,
  229,
  50,
  373197,
  6029,
  19,
  86884,
  243745,
  335656,
  90945,
  38973,
  572950,
  164129,
  0,
  3,
  17,
  13579,
  4448,
  47,
  3,
  132966,
  726249,
  498503,
  256,
  0,
  25841,
  0,
  7,
  945380,
  11872,
  69,
  3799,
  77223,
  1914,
  73,
  810968,
  10223,
  257918,
  184252,
  350,
  8101,
  725,
  9,
  2,
  2089,
  175,
  247,
  185964,
  36517,
  3723,
  313465,
  209,
  1300,
  128071,
  7425,
  2436,
  62,
  13753,
  9514,
  41,
  409141,
  46643,
  20866,
  15664,
  388548,
  84692,
  9549,
  610,
  7213,
  14,
  14930,
  244719,
  4748,
  41682,
  401098,
  102506,
  176535,
  0,
  5133,
  548,
  5234,
  56,
  11101,
  87638,
  336579,
  291705,
  640250,
  768165,
  370,
  2809,
  3,
  0,
  445122,
  47190,
  24885,
  143556,
  84,
  504726,
  610020,
  40355,
  902230,
  4360,
  1747,
  3496,
  489501,
  19,
  801601,
  62189,
  48,
  2645,
  320601,
  27304,
  17740,
  344,
  10,
  991,
  925503,
  0,
  315,
  251,
  3611,
  1756,
  683,
  165,
  380132,
  181101,
  453041,
  892056,
  67191,
  252592,
  32407,
  56242,
  8,
  297173,
  542903,
  830334,
  585236,
  422555,
  44769,
  0,
  68,
  4143,
  38754,
  73539,
  44579,
  94001,
  428537,
  38554,
  106612,
  0,
  182987,
  831731,
  3605,
  752851,
  52,
  72,
  120872,
  963754,
  31,
  764,
  240592,
  99101,
  328538,
  440325,
  12211,
  151282,
  353436,
  2991,
  40710,
  5212,
  5106,
  139122,
  148915,
  498505,
  1366,
  516,
  29190,
  17,
  224208,
  40,
  89,
  19190,
  8,
  25377,
  10029,
  720,
  97963,
  0,
  614,
  244567,
  2113,
  903675,
  8388,
  6,
  390705,
  325006,
  284272,
  108086,
  17,
  2628,
  952530,
  20474,
  898276,
  138661,
  3883,
  903,
  569993,
  376918,
  5849,
  103404,
  794499,
  35388,
  5,
  0,
  961626,
  27415,
  1927,
  92036,
  46241,
  35978,
  7426,
  399884,
  29490,
  252655,
  675971,
  3509,
  54170,
  170790,
  831341,
  134579,
  0,
  790422,
  35,
  930830,
  97394,
  20265,
  670,
  38497,
  1759,
  71209,
  93,
  736,
  11,
  886,
  1961,
  7,
  210607,
  62226,
  186736,
  1518,
  5,
  5,
  13,
  66989,
  442321,
  0,
  607939,
  11253,
  210875,
  495530,
  2,
  221136,
  377663,
  372,
  200658,
  18591,
  129783,
  803411,
  867506,
  757446,
  48836,
  34,
  200,
  114983,
  7287,
  22849,
  226669,
  13,
  0,
  20164,
  7828,
  39,
  49448,
  26740,
  185566,
  9927,
  36192,
  91068,
  338368,
  926,
  27746,
  534794,
  936132,
  2922,
  5,
  183162,
  256846,
  242551,
  134318,
  212959,
  167162,
  470,
  477045,
  532116,
  483794,
  733,
  5335,
  83074,
  4686,
  9567,
  1,
  195100,
  40354,
  87338,
  369,
  800,
  0,
  194504,
  469051,
  363532,
  850574,
  5085,
  167027,
  794511,
  124320,
  303231,
  132195,
  13225,
  46333,
  4313,
  89,
  799,
  51482,
  0,
  26,
  12659,
  1045,
  23621,
  0,
  74926,
  490979,
  6,
  3188,
  9448,
  174730,
  38982,
  102317,
  189621,
  853,
  29227,
  43374,
  423,
  420951,
  686,
  128,
  31291,
  0,
  402819,
  663143,
  55903,
  142,
  2,
  331584,
  197164,
  7,
  671983,
  53,
  5020,
  9782,
  123,
  743407,
  1276,
  1115,
  1169,
  122752,
  824690,
  292030,
  2094,
  144626,
  0,
  297278,
  440,
  742,
  95879,
  17682,
  10654,
  31,
  22183,
  746,
  0,
  0,
  11185,
  28,
  394987,
  36,
  474,
  243749,
  1431,
  56702,
  76,
  15619,
  33071,
  12181,
  158647,
  261786,
  1,
  119783,
  48816,
  6278,
  4121,
  61122,
  69,
  48790,
  345335,
  275917,
  964393,
  424,
  586433,
  20519,
  18156,
  756400,
  27736,
  458706,
  1,
  3286,
  929624,
  1883,
  2,
  1086,
  439501,
  552,
  157132,
  5565,
  105061,
  8199,
  23,
  178797,
  0,
  130644,
  1,
  6952,
  754,
  500,
  647683,
  0,
  959079,
  622561,
  1131,
  559783,
  6862,
  175420,
  408671,
  463461,
  55908,
  606496,
  169,
  49060,
  247,
  953,
  333030,
  0,
  23399,
  29193,
  9303,
  15,
  515402,
  34961,
  365856,
  633043,
  173,
  556089,
  1809,
  12215,
  14,
  316,
  20642,
  9,
  15,
  190391,
  951463,
  25059,
  13654,
  385040,
  4272,
  929033,
  208813,
  35166,
  42849,
  662648,
  254811,
  4230,
  812459,
  681,
  390168,
  5381,
  4662,
  173257,
  478863,
  103,
  89332,
  0,
  0,
  589484,
  19369,
  94,
  9,
  639917,
  1110,
  393,
  101040,
  911,
  152899,
  0,
  2,
  0,
  0,
  335691,
  43694,
  62273,
  200121,
  2250,
  621004,
  149918,
  41063,
  218229,
  0,
  497924,
  16832,
  587071,
  0,
  0,
  729918,
  2,
  808513,
  9417,
  718,
  0,
  2769,
  28704,
  1335,
  734726,
  219157,
  786230,
  981004,
  350788,
  884529,
  0,
  87872,
  34647,
  85469,
  4524,
  339838,
  38228,
  0,
  4151,
  1145,
  0,
  351,
  167956,
  810075,
  689,
  251212,
  583068,
  2929,
  189456,
  2089,
  48749,
  278952,
  77134,
  0,
  0,
  45595,
  281829,
  969602,
  43999,
  69824,
  856982,
  61732,
  336,
  25488,
  213,
  46683,
  1909,
  174097,
  57930,
  91466,
  828418,
  95740,
  378828,
  128065,
  68068,
  0,
  13312,
  26006,
  6760,
  51,
  276081,
  640068,
  634985,
  7131,
  784882,
  790126,
  628585,
  205824,
  764965,
  17793,
  3159,
  649924,
  0,
  37383,
  9919,
  353,
  0,
  149003,
  620629,
  95928,
  2560,
  504343,
  1000,
  32,
  43836,
  407031,
  207,
  800894,
  3222,
  51028,
  7,
  6,
  22010,
  0,
  21174,
  12893,
  824932,
  7305,
  70,
  624258,
  372139,
  21504,
  387996,
  418931,
  914268,
  576,
  0,
  0,
  618224,
  787516,
  133014,
  422,
  383124,
  656318,
  4420,
  6082,
  244813,
  38585,
  3200,
  1,
  2,
  11882,
  113,
  45581,
  13121,
  95475,
  807219,
  8195,
  995116,
  13,
  2146,
  369925,
  60103,
  25,
  125165,
  51300,
  4894,
  173261,
  74186,
  1044,
  122992,
  1243,
  21703,
  26294,
  197,
  333825,
  426872,
  719580,
  3598,
  106,
  0,
  9932,
  61509,
  146,
  721428,
  964781,
  319850,
  573802,
  7458,
  317889,
  0,
  133086,
  87836,
  60496,
  304249,
  1565,
  27,
  42,
  899324,
  189637,
  8648,
  104570,
  901598,
  447765,
  24,
  108,
  120127,
  828626,
  8,
  899514,
  28,
  13,
  7576,
  163390,
  1625,
  3023,
  155175,
  2,
  391,
  1,
  493073,
  398,
  210771,
  26266,
  287999,
  38255,
  249666,
  598202,
  119601,
  216933,
  91205,
  0,
  7247,
  77077,
  565383,
  29102,
  253641,
  48855,
  19722,
  463536,
  40182,
  65393,
  829444,
  598402,
  1590,
  798,
  467,
  834847,
  3007,
  13711,
  0,
  195,
  101662,
  255749,
  129201,
  11965,
  1781,
  13349,
  3100,
  718066,
  99,
  712450,
  888215,
  42503,
  43171,
  494946,
  0,
  2175,
  12387,
  25662,
  78,
  739030,
  0,
  19,
  427526,
  4275,
  5583,
  0,
  2447,
  132398,
  26437,
  3873,
  440035,
  21,
  6,
  35432,
  41523,
  7179,
  712703,
  428868,
  2793,
  6,
  286277,
  1882,
  95116,
  2959,
  86,
  115425,
  81386,
  59836,
  37,
  247598,
  34732,
  249,
  500110,
  5589,
  40319,
  575,
  12145,
  385829,
  565600,
  582150,
  92,
  223209,
  0,
  910,
  1048,
  47329,
  90944,
  235,
  8739,
  686685,
  1753,
  126,
  434,
  609477,
  25021,
  6610,
  52675,
  4,
  717846,
  150864,
  418583,
  17751,
  513794,
  181362,
  329556,
  10426,
  717019,
  457,
  616,
  388984,
  17,
  8338,
  59531,
  32,
  99565,
  376146,
  134578,
  966,
  0,
  0,
  174,
  2105,
  555,
  8990,
  298,
  169932,
  247281,
  240918,
  298655,
  158743,
  15994,
  95708,
  51,
  2985,
  4294,
  731934,
  185640,
  1483,
  87,
  742033,
  9,
  1345,
  3680,
  133530,
  9355,
  800111,
  28508,
  0,
  369,
  31681,
  24,
  8237,
  313380,
  4732,
  275423,
  951592,
  0,
  41381,
  225515,
  393004,
  526,
  187,
  19515,
  6006,
  28923,
  310151,
  2390,
  374,
  0,
  19142,
  72,
  114,
  193305,
  24035,
  397067,
  18,
  14839,
  3473,
  164,
  104622,
  378958,
  2218,
  0,
  89053,
  105183,
  312265,
  82146,
  147210,
  3419,
  5178,
  34948,
  46836,
  41319,
  842825,
  595972,
  0,
  249625,
  325,
  608,
  372328,
  119634,
  7504,
  920214,
  7302,
  444532,
  359213,
  27265,
  1755,
  48,
  126799,
  651270,
  818220,
  799493,
  724024,
  64047,
  73699,
  206999,
  209,
  1581,
  0,
  42937,
  301144,
  73416,
  0,
  242058,
  29660,
  3,
  34709,
  162719,
  2863,
  3992,
  5212,
  151814,
  3092,
  198001,
  44331,
  36,
  407,
  364771,
  1349,
  502772,
  214726,
  607,
  388583,
  137660,
  337124,
  13279,
  10549,
  943075,
  164068,
  19157,
  38443,
  26351,
  0,
  67167,
  735,
  46486,
  130305,
  232330,
  744,
  882337,
  2,
  69275,
  126354,
  9370,
  2845,
  299,
  38988,
  37834,
  0,
  306433,
  9139,
  237132,
  0,
  500,
  13462,
  373684,
  107453,
  381924,
  347915,
  4329,
  1668,
  3960,
  370661,
  3614,
  636048,
  0,
  487449,
  64925,
  333894,
  11,
  52192,
  531200,
  155554,
  461,
  1547,
  994361,
  11955,
  321056,
  37425,
  14249,
  69151,
  621862,
  174,
  79607,
  34,
  77577,
  13723,
  267550,
  13801,
  698,
  12,
  171556,
  57354,
  676845,
  0,
  24965,
  908955,
  570483,
  0,
  296387,
  983966,
  85012,
  130298,
  151946,
  384474,
  731455,
  150699,
  772,
  216131,
  346,
  130935,
  3472,
  18,
  426045,
  677262,
  808,
  17030,
  5188,
  0,
  491153,
  67299,
  19,
  60342,
  69,
  0,
  76478,
  95763,
  0,
  28778,
  147869,
  335927,
  27846,
  2163,
  22750,
  162,
  23,
  11391,
  469099,
  5852,
  63,
  0,
  0,
  22193,
  165,
  489007,
  9249,
  12477,
  2841,
  223532,
  13877,
  173,
  3570,
  45477,
  233073,
  23296,
  64377,
  4910,
  8,
  76246,
  411147,
  287411,
  10450,
  3667,
  1,
  500933,
  31363,
  257,
  1705,
  6036,
  49934,
  13738,
  13485,
  61608,
  561978,
  76493,
  16377,
  1817,
  0,
  235600,
  0,
  16347,
  680478,
  5115,
  895607,
  138270,
  369912,
  53110,
  0,
  647083,
  85,
  458681,
  163227,
  52767,
  196,
  267719,
  14047,
  147293,
  814457,
  174896,
  0,
  34138,
  36,
  21575,
  3,
  0,
  0,
  38391,
  2597,
  2,
  1433,
  3807,
  36476,
  287,
  141530,
  29389,
  495655,
  30014,
  0,
  550766,
  11958,
  348,
  226760,
  15,
  251353,
  675788,
  518308,
  215,
  81987,
  409862,
  559596,
  114283,
  4925,
  0,
  17,
  14221,
  0,
  162,
  766370,
  4898,
  998,
  493,
  138418,
  265159,
  12152,
  5229,
  1204,
  1814,
  432530,
  2889,
  144,
  1149,
  35886,
  636931,
  6640,
  1508,
  414118,
  858,
  20039,
  17398,
  3,
  5094,
  6,
  13996,
  6754,
  362,
  451487,
  11471,
  7896,
  330009,
  244269,
  99928,
  0,
  14311,
  9949,
  15251,
  283923,
  123754,
  188360,
  93902,
  854384,
  548001,
  531788,
  26298,
  328479,
  941,
  246535,
  106320,
  28769,
  440,
  4,
  61262,
  55615,
  170,
  989327,
  692534,
  8063,
  445842,
  4434,
  255349,
  117781,
  6,
  9249,
  136216,
  38165,
  307012,
  12,
  2341,
  18062,
  371882,
  662154,
  12623,
  176847,
  332220,
  590935,
  33682,
  0,
  121374,
  67,
  46841,
  495890,
  640,
  19,
  14737,
  11032,
  17,
  5993,
  302562,
  827710,
  165346,
  49607,
  87863,
  308513,
  735300,
  1914,
  2900,
  207308,
  9068,
  83494,
  179,
  417,
  41605,
  74681,
  652171,
  4013,
  29811,
  13966,
  8136,
  78,
  61182,
  674187,
  0,
  331121,
  0,
  18559,
  386,
  77,
  348439,
  975358,
  18,
  33700,
  47396,
  204751,
  2350,
  26503,
  0,
  83653,
  446,
  10844,
  485,
  9241,
  88347,
  232419,
  936900,
  43250,
  2,
  26112,
  811955,
  20723,
  102069,
  42255,
  8431,
  119508,
  4080,
  13565,
  12,
  46110,
  62096,
  638777,
  44025,
  152985,
  13362,
  3,
  12331,
  193337,
  56419,
  14593,
  3837,
  282314,
  403454,
  48589,
  135,
  18350,
  2160,
  90,
  918216,
  7083,
  105534,
  742826,
  399028,
  1470,
  23770,
  480,
  677884,
  340472,
  107406,
  0,
  5002,
  445,
  748948,
  534012,
  592464,
  6539,
  819632,
  3138,
  4,
  39397,
  229683,
  12204,
  2439,
  65131,
  817226,
  22596,
  0,
  1046,
  94638,
  0,
  95403,
  1230,
  790056,
  19976,
  43085,
  14251,
  139187,
  20232,
  693,
  3058,
  27654,
  65690,
  40948,
  15001,
  21089,
  14425,
  322459,
  13571,
  228154,
  536814,
  761221,
  28030,
  2322,
  921,
  1,
  1137,
  187815,
  8,
  34911,
  4527,
  15,
  46,
  78801,
  0,
  73605,
  44,
  28233,
  1370,
  73409,
  198159,
  66586,
  3,
  2576,
  15,
  35460,
  263237,
  44997,
  2873,
  240,
  1781,
  269,
  46,
  272778,
  28404,
  8232,
  417073,
  234591,
  9,
  720349,
  1176,
  16195,
  0,
  9705,
  0,
  14,
  947048,
  163,
  76288,
  1115,
  267020,
  3416,
  414217,
  441004,
  95131,
  765002,
  6196,
  9069,
  27017,
  137039,
  65247,
  266489,
  484945,
  187008,
  45405,
  5700,
  9,
  7751,
  12,
  294,
  3093,
  6350,
  103303,
  6045,
  252345,
  140207,
  22390,
  234867,
  443326,
  1,
  0,
  89972,
  8637,
  427150,
  22146,
  0,
  310432,
  390333,
  10461,
  1632,
  31403,
  908653,
  0,
  6543,
  163479,
  67608,
  195543,
  315889,
  822964,
  383536,
  954954,
  1619,
  241,
  96053,
  104556,
  767302,
  2469,
  12,
  164330,
  78,
  141,
  170519,
  268214,
  53338,
  48342,
  721,
  58980,
  4345,
  1,
  856265,
  87289,
  57219,
  775679,
  123992,
  695804,
  113025,
  832,
  117420,
  16634,
  352,
  24729,
  14973,
  25622,
  131290,
  0,
  22,
  87740,
  5917,
  533,
  2934,
  34261,
  9174,
  0,
  1656,
  764587,
  54652,
  35597,
  36389,
  577889,
  63957,
  26808,
  34556,
  56,
  15641,
  137,
  1,
  3,
  11724,
  197397,
  39027,
  87902,
  320,
  791479,
  7,
  487864,
  0,
  433,
  25733,
  6956,
  15407,
  312557,
  526302,
  383019,
  340215,
  96,
  276158,
  6493,
  135613,
  2000,
  1218,
  930,
  276808,
  273249,
  8896,
  397,
  735095,
  20648,
  2079,
  5349,
  205,
  356313,
  841954,
  8255,
  266874,
  0,
  965,
  287993,
  1549,
  207833,
  75,
  178180,
  39072,
  0,
  43254,
  3847,
  227,
  2712,
  161043,
  463264,
  74720,
  795789,
  12,
  6812,
  202804,
  29379,
  64241,
  132121,
  790622,
  493588,
  0,
  48,
  147352,
  925197,
  38149,
  18380,
  0,
  270280,
  633,
  3373,
  31294,
  7830,
  0,
  0,
  11371,
  56143,
  5393,
  74724,
  495109,
  0,
  18993,
  21524,
  0,
  53889,
  400509,
  204563,
  0,
  11625,
  9635,
  0,
  1678,
  12096,
  59,
  817112,
  10002,
  128209,
  11593,
  17313,
  15200,
  106796,
  261401,
  707077,
  0,
  314030,
  798591,
  14175,
  5668,
  2766,
  0,
  566,
  5543,
  24112,
  154482,
  5642,
  0,
  38410,
  3,
  4,
  700724,
  25024,
  5,
  407,
  564150,
  672,
  143,
  2049,
  574708,
  65858,
  213412,
  3797,
  511,
  30907,
  1212,
  765,
  2127,
  481,
  130048,
  113816,
  39861,
  153169,
  503378,
  523944,
  111,
  55083,
  698,
  275,
  3,
  3195,
  1657,
  0,
  317881,
  6672,
  543,
  153011,
  77240,
  9338,
  889850,
  29518,
  872485,
  181927,
  376086,
  266,
  409,
  4,
  14856,
  31943,
  2448,
  8,
  75,
  383097,
  294366,
  0,
  173084,
  753160,
  66457,
  725783,
  51,
  127651,
  1073,
  12598,
  140080,
  0,
  296375,
  581720,
  217346,
  8272,
  2051,
  185390,
  520645,
  1260,
  13873,
  168040,
  19690,
  103347,
  295011,
  548404,
  48,
  4,
  916417,
  1948,
  621365,
  263245,
  2792,
  86803,
  181193,
  558081,
  50907,
  442770,
  51448,
  340276,
  1346,
  607,
  459627,
  0,
  30,
  73298,
  15389,
  12264,
  2719,
  2936,
  143043,
  209970,
  0,
  42,
  6657,
  317419,
  0,
  32622,
  524000,
  0,
  310331,
  303778,
  268710,
  9,
  10410,
  25343,
  949506,
  784353,
  3861,
  46823,
  251292,
  75008,
  269798,
  87731,
  112813,
  571679,
  385,
  3,
  2811,
  36025,
  9243,
  935128,
  906,
  10688,
  25,
  86757,
  307,
  55,
  22,
  2,
  61,
  620426,
  484530,
  633806,
  0,
  1342,
  9293,
  992181,
  503,
  195433,
  46150,
  893091,
  3207,
  2865,
  72894,
  830299,
  355,
  327479,
  0,
  35573,
  3068,
  15699,
  31187,
  55378,
  416067,
  91721,
  159,
  0,
  255139,
  2104,
  19,
  606757,
  323,
  902659,
  365655,
  400,
  903,
  408,
  385,
  21774,
  701290,
  234426,
  17020,
  950,
  0,
  0,
  429,
  1245,
  405871,
  1097,
  280634,
  74,
  158233,
  1583,
  180333,
  42114,
  575973,
  539327,
  59252,
  121928,
  165,
  148501,
  55757,
  7494,
  127728,
  7832,
  68504,
  619770,
  70995,
  312816,
  7307,
  38265,
  46248,
  363304,
  269442,
  77112,
  448331,
  910442,
  474418,
  152752,
  752,
  104912,
  408492,
  691709,
  632381,
  48519,
  20524,
  344294,
  14670,
  0,
  21607,
  81162,
  181458,
  0,
  908322,
  7261,
  10888,
  58054,
  1788,
  970933,
  5925,
  121553,
  36152,
  588267,
  23615,
  1850,
  30728,
  3599,
  1319,
  6027,
  0,
  32141,
  984156,
  436781,
  15003,
  621407,
  9412,
  562911,
  189740,
  377895,
  656800,
  197,
  14413,
  99382,
  384,
  11480,
  0,
  86118,
  881961,
  1905,
  82061,
  4140,
  741153,
  26,
  687,
  12251,
  10945,
  209267,
  220602,
  135881,
  6,
  237945,
  158,
  5,
  76303,
  81344,
  986042,
  956063,
  30282,
  186055,
  357802,
  12492,
  577476,
  838,
  0,
  11,
  117602,
  0,
  187928,
  96860,
  4268,
  3478,
  818264,
  1649,
  17175,
  272,
  158951,
  440987,
  677594,
  14935,
  37953,
  0,
  198,
  160404,
  12,
  287803,
  2386,
  10,
  271663,
  319152,
  361322,
  68370,
  428,
  182707,
  387429,
  1152,
  360065,
  25218,
  2790,
  42228,
  13,
  110942,
  452491,
  1,
  665638,
  2308,
  1196,
  87306,
  66,
  219,
  0,
  130736,
  334,
  605,
  5979,
  2681,
  0,
  123463,
  11219,
  283681,
  19269,
  553,
  6217,
  130965,
  714409,
  242,
  674833,
  237581,
  133284,
  683,
  1758,
  278193,
  518726,
  44,
  420361,
  325228,
  14955,
  10,
  11994,
  64157,
  1937,
  20214,
  848,
  27804,
  151341,
  79236,
  316393,
  158883,
  1196,
  334,
  22797,
  185955,
  13857,
  397357,
  7948,
  6038,
  0,
  2621,
  16,
  155267,
  44809,
  9171,
  21328,
  12212,
  40200,
  2600,
  439,
  804014,
  10938,
  96135,
  43696,
  158715,
  4,
  284558,
  191,
  270254,
  7923,
  880603,
  21032,
  107700,
  172,
  700823,
  5613,
  78816,
  258290,
  214398,
  821856,
  295325,
  0,
  1,
  23559,
  63895,
  21249,
  717490,
  956952,
  944819,
  793,
  356,
  757716,
  111773,
  394826,
  25665,
  4358,
  640216,
  1152,
  37175,
  150192,
  106071,
  28992,
  67,
  1685,
  134242,
  2,
  102045,
  1457,
  419589,
  6789,
  677,
  94675,
  11300,
  2595,
  8,
  926535,
  265194,
  0,
  886048,
  246242,
  1494,
  191,
  169985,
  649765,
  0,
  201,
  1069,
  679163,
  16627,
  274639,
  84438,
  3,
  1301,
  247496,
  5879,
  710904,
  403652,
  958241,
  361,
  139732,
  6042,
  15985,
  2378,
  267031,
  223767,
  9656,
  241717,
  33863,
  14314,
  205697,
  1274,
  168000,
  621777,
  837913,
  89654,
  659829,
  69,
  503884,
  432717,
  70443,
  110891,
  19655,
  132432,
  620401,
  428,
  0,
  425662,
  0,
  0,
  0,
  194489,
  7601,
  26870,
  0,
  63,
  594,
  12278,
  582479,
  213723,
  424489,
  96446,
  990664,
  46966,
  44137,
  829810,
  104,
  19707,
  16,
  0,
  2499,
  167075,
  140972,
  249283,
  6620,
  68368,
  856414,
  9255,
  14315,
  0,
  11432,
  24329,
  216463,
  299556,
  818401,
  246607,
  697733,
  229,
  144,
  389394,
  664634,
  0,
  19393,
  657903,
  52912,
  952177,
  536931,
  187271,
  17687,
  970155,
  232571,
  234016,
  159980,
  13510,
  32952,
  0,
  0,
  24132,
  18806,
  15624,
  28364,
  472126,
  626978,
  599,
  112843,
  502933,
  915660,
  63920,
  0,
  84,
  10899,
  904823,
  126,
  469132,
  590052,
  195831,
  443113,
  294149,
  15944,
  2271,
  282974,
  211,
  0,
  22934,
  82283,
  49973,
  41707,
  87530,
  0,
  910528,
  0,
  36029,
  423337,
  817512,
  223671,
  27800,
  398847,
  198528,
  1,
  560679,
  518270,
  23033,
  501059,
  0,
  3909,
  272062,
  261581,
  187,
  52043,
  334,
  24354,
  3947,
  8549,
  37863,
  328851,
  963771,
  1,
  3930,
  82416,
  6,
  2943,
  122101,
  82577,
  85,
  89540,
  5135,
  109236,
  18297,
  1,
  177371,
  4541,
  769577,
  178,
  417,
  960566,
  33803,
  911651,
  248160,
  153725,
  43981,
  809174,
  116,
  486900,
  4842,
  148490,
  131534,
  4347,
  239949,
  984096,
  749756,
  429499,
  2794,
  78209,
  18812,
  21111,
  490,
  328042,
  12,
  132119,
  505103,
  353148,
  0,
  373656,
  951244,
  491,
  355778,
  30620,
  317,
  60175,
  220,
  214496,
  41249,
  5169,
  78367,
  506804,
  0,
  1368,
  407,
  295126,
  1288,
  86,
  97614,
  61640,
  244723,
  3,
  0,
  869827,
  527246,
  52,
  107036,
  240739,
  780281,
  113084,
  62009,
  740343,
  483201,
  8649,
  16419,
  1,
  801574,
  95524,
  326126,
  26912,
  877040,
  10262,
  5895,
  0,
  132633,
  59171,
  306347,
  702701,
  196245,
  12642,
  32723,
  24608,
  30287,
  45775,
  18281,
  7587,
  144532,
  5,
  35,
  99862,
  215127,
  170875,
  61461,
  77790,
  5,
  0,
  129358,
  0,
  105084,
  21399,
  42233,
  85397,
  480654,
  555988,
  89575,
  42346,
  20004,
  11102,
  21321,
  185,
  379267,
  849147,
  121514,
  3388,
  33662,
  12,
  164898,
  226,
  274,
  385003,
  365052,
  693376,
  41245,
  9010,
  41594,
  89835,
  10490,
  272,
  128437,
  0,
  122648,
  277,
  116505,
  38372,
  4,
  1376,
  0,
  46317,
  139368,
  36398,
  193899,
  30632,
  26371,
  7548,
  367643,
  954849,
  25889,
  36567,
  176,
  140631,
  4690,
  975031,
  80965,
  500471,
  8442,
  43,
  27758,
  301501,
  3797,
  80,
  384440,
  928477,
  4960,
  24566,
  33245,
  14638,
  228354,
  54347,
  861285,
  12841,
  2,
  157402,
  646747,
  53763,
  1,
  214732,
  49471,
  49757,
  998,
  201135,
  566,
  73512,
  194240,
  391773,
  21510,
  13,
  829894,
  783200,
  565329,
  2101,
  12,
  191043,
  1621,
  18443,
  279,
  294135,
  526503,
  729735,
  4639,
  444138,
  5835,
  12372,
  46362,
  1543,
  870907,
  83262,
  0,
  38331,
  95,
  1194,
  909,
  8053,
  453066,
  845561,
  411,
  3229,
  1,
  158,
  1431,
  835137,
  21774,
  7298,
  148388,
  224649,
  379318,
  520138,
  39781,
  172130,
  362634,
  487495,
  51957,
  158,
  1770,
  7,
  18010,
  1063,
  171484,
  19924,
  279867,
  469956,
  189785,
  0,
  814,
  60580,
  944349,
  18743,
  553235,
  0,
  95475,
  99,
  0,
  5,
  42623,
  178418,
  398940,
  5700,
  69023,
  5786,
  0,
  10531,
  551,
  86308,
  63451,
  32704,
  176903,
  0,
  251689,
  11589,
  25711,
  43437,
  1431,
  304,
  52965,
  34816,
  268688,
  47756,
  825323,
  122608,
  81246,
  69974,
  360515,
  99973,
  143015,
  5063,
  4499,
  34459,
  171982,
  677943,
  489082,
  257515,
  3765,
  5,
  7416,
  602206,
  74122,
  3,
  686204,
  5493,
  28901,
  11349,
  549668,
  257082,
  82000,
  17031,
  1517,
  7442,
  937160,
  722,
  0,
  72952,
  377192,
  438266,
  555,
  31436,
  284,
  56390,
  0,
  585856,
  27635,
  519344,
  126131,
  360273,
  845073,
  0,
  191965,
  55652,
  23,
  112773,
  639025,
  84749,
  0,
  330822,
  7173,
  126217,
  871,
  112112,
  0,
  664,
  530474,
  1,
  379564,
  172617,
  647308,
  0,
  356,
  17,
  84345,
  457,
  0,
  8,
  6,
  136602,
  634424,
  0,
  177298,
  100726,
  91661,
  383792,
  1665,
  43583,
  15775,
  4083,
  4277,
  345749,
  969599,
  65804,
  19327,
  0,
  352514,
  4225,
  9,
  103767,
  0,
  0,
  148436,
  850,
  33,
  2146,
  20153,
  50,
  9063,
  50329,
  348379,
  2569,
  83697,
  37073,
  715486,
  629,
  4753,
  442,
  259203,
  287223,
  48625,
  9,
  70184,
  45946,
  144947,
  0,
  60285,
  28640,
  7626,
  134159,
  33,
  12452,
  150566,
  348293,
  124426,
  353952,
  11,
  22,
  776742,
  29072,
  132168,
  254533,
  319957,
  1602,
  1659,
  209341,
  32847,
  92392,
  753005,
  1392,
  10271,
  28557,
  6717,
  941745,
  0,
  0,
  0,
  78645,
  45320,
  11193,
  1448,
  130626,
  377907,
  795535,
  24285,
  26094,
  266691,
  64449,
  77400,
  191410,
  1,
  1346,
  25224,
  489637,
  47052,
  248592,
  76689,
  0,
  7722,
  47285,
  3152,
  285577,
  0,
  149366,
  264346,
  1,
  208602,
  320459,
  131771,
  1421,
  350,
  723283,
  714934,
  0,
  566439,
  11656,
  34189,
  125484,
  943273,
  15,
  7789,
  0,
  7427,
  464278,
  680924,
  651102,
  87794,
  39640,
  838644,
  964500,
  1,
  1765,
  272604,
  10,
  837347,
  44845,
  130,
  163357,
  4150,
  403331,
  839132,
  44876,
  272792,
  592527,
  57225,
  128826,
  2915,
  2,
  3570,
  2410,
  199,
  171358,
  5931,
  53620,
  55299,
  1868,
  24123,
  165,
  346513,
  16527,
  133,
  517412,
  195700,
  730365,
  896209,
  152760,
  24577,
  65,
  8218,
  349642,
  901345,
  5127,
  5102,
  238318,
  955,
  631921,
  12218,
  55101,
  930381,
  219503,
  469237,
  132,
  16701,
  494,
  199729,
  0,
  32139,
  314,
  172,
  2947,
  106997,
  4871,
  236,
  6146,
  1843,
  128,
  0,
  254240,
  2964,
  14825,
  60624,
  2108,
  286953,
  654931,
  0,
  0,
  396587,
  19852,
  70311,
  363561,
  282,
  17966,
  924254,
  104173,
  130816,
  179096,
  105466,
  136,
  618261,
  358433,
  25587,
  49357,
  102,
  133746,
  620776,
  17084,
  406881,
  802675,
  349,
  69,
  8761,
  278482,
  16336,
  128,
  160096,
  25857,
  280,
  39639,
  726299,
  293905,
  4621,
  41,
  649,
  3655,
  269286,
  578026,
  0,
  11156,
  1,
  744858,
  531,
  48155,
  28435,
  7991,
  447,
  10201,
  379341,
  0,
  5773,
  0,
  295,
  228592,
  331155,
  104089,
  628069,
  29693,
  22,
  13,
  0,
  0,
  554349,
  6082,
  238,
  23,
  151873,
  805937,
  0,
  194076,
  6450,
  3,
  128322,
  69149,
  95511,
  86,
  844368,
  415964,
  51985,
  308686,
  553403,
  624943,
  365800,
  4,
  120263,
  91239,
  195248,
  58010,
  19,
  415112,
  136806,
  42,
  571848,
  55306,
  29454,
  3,
  144926,
  189,
  0,
  161943,
  592155,
  10930,
  279297,
  56932,
  957430,
  10244,
  190296,
  807209,
  781,
  1466,
  235055,
  33,
  196,
  58280,
  436,
  408649,
  221,
  711143,
  10495,
  2441,
  275720,
  2,
  15391,
  132107,
  102610,
  688549,
  237142,
  3041,
  14,
  308623,
  0,
  0,
  287,
  295147,
  61443,
  229,
  207,
  2051,
  64,
  13479,
  55656,
  570134,
  50387,
  225869,
  20615,
  258465,
  64932,
  112461,
  164521,
  907269,
  758563,
  22901,
  0,
  7944,
  48,
  154921,
  2784,
  548608,
  0,
  12524,
  142556,
  0,
  13882,
  507227,
  316598,
  987551,
  0,
  894687,
  1964,
  364,
  10316,
  440269,
  9,
  776723,
  72288,
  54604,
  185101,
  142,
  362,
  11679,
  77,
  79,
  529321,
  364,
  42387,
  0,
  570879,
  417503,
  604871,
  578806,
  1102,
  66584,
  615440,
  146744,
  19441,
  170478,
  144069,
  36170,
  145376,
  842283,
  193612,
  3,
  359429,
  368596,
  0,
  11064,
  7726,
  229410,
  63569,
  67402,
  91,
  203201,
  213513,
  0,
  704479,
  1325,
  0,
  385154,
  13,
  806763,
  197132,
  6183,
  45760,
  99377,
  0,
  972077,
  4043,
  195700,
  34229,
  0,
  154027,
  633,
  6,
  32142,
  0,
  29,
  620842,
  14099,
  495465,
  26937,
  0,
  0,
  432,
  227704,
  0,
  63,
  0,
  19,
  863491,
  20,
  1,
  160713,
  24607,
  85800,
  3566,
  37854,
  81913,
  121573,
  816,
  20,
  133253,
  692231,
  4869,
  255175,
  15028,
  9383,
  542877,
  4608,
  369610,
  243635,
  385285,
  391565,
  286009,
  0,
  61685,
  416318,
  208,
  67019,
  788416,
  88,
  165056,
  0,
  439589,
  160,
  105528,
  152,
  160624,
  865,
  390229,
  714086,
  6007,
  30229,
  481306,
  173266,
  1135,
  2266,
  8,
  59,
  104722,
  647885,
  579471,
  21309,
  230834,
  140278,
  31858,
  3288,
  36011,
  151387,
  594217,
  22439,
  418638,
  76859,
  29363,
  154809,
  275533,
  39,
  472996,
  22076,
  7481,
  155705,
  10406,
  214779,
  223,
  1312,
  16391,
  17203,
  55605,
  44579,
  69332,
  303,
  19217,
  26288,
  126212,
  316,
  98,
  114,
  37382,
  137591,
  439749,
  12972,
  54,
  154879,
  0,
  102680,
  7639,
  309119,
  263550,
  766,
  1124,
  56,
  686608,
  123767,
  518054,
  18,
  672385,
  3161,
  53791,
  26769,
  451670,
  61,
  148245,
  2713,
  96725,
  4794,
  33247,
  297946,
  33380,
  0,
  20034,
  5647,
  17227,
  76444,
  0,
  21011,
  675,
  13226,
  1027,
  990842,
  124459,
  34406,
  53,
  69540,
  134,
  0,
  168521,
  6,
  4075,
  1137,
  63740,
  220,
  10434,
  1171,
  28950,
  0,
  79680,
  993269,
  355622,
  15,
  0,
  1452,
  21667,
  22208,
  494484,
  33984,
  691308,
  10,
  693686,
  196,
  9,
  70676,
  157660,
  775,
  165,
  468432,
  1083,
  515154,
  778344,
  70241,
  42,
  40931,
  277125,
  43837,
  301881,
  1332,
  56712,
  9013,
  1299,
  7564,
  31092,
  1975,
  113517,
  833295,
  245021,
  36503,
  23586,
  149327,
  89175,
  10512,
  484348,
  187793,
  954609,
  53199,
  792175,
  126,
  12369,
  405,
  0,
  6614,
  322857,
  166,
  571874,
  60839,
  180975,
  146722,
  411565,
  1536,
  1,
  11,
  116230,
  60514,
  9003,
  2325,
  43763,
  63,
  355553,
  0,
  389876,
  14672,
  11526,
  160209,
  65,
  10283,
  966,
  10,
  58333,
  129920,
  2850,
  83346,
  0,
  14,
  295819,
  679550,
  143928,
  29489,
  82324,
  36558,
  267118,
  143313,
  90107,
  12789,
  951,
  0,
  187619,
  295317,
  82,
  41326,
  309682,
  907327,
  809358,
  324,
  139157,
  12,
  78366,
  671811,
  354,
  131,
  70525,
  35830,
  281018,
  91456,
  92523,
  54874,
  48273,
  2423,
  0,
  81,
  361314,
  374811,
  394758,
  15350,
  795,
  3,
  16779,
  796684,
  477556,
  73927,
  26643,
  119281,
  62692,
  17039,
  454778,
  952,
  48973,
  19529,
  151,
  239121,
  93509,
  254702,
  1307,
  10029,
  7973,
  546706,
  806644,
  680517,
  223,
  0,
  2,
  0,
  402421,
  619193,
  15685,
  2,
  939715,
  519198,
  0,
  444312,
  23204,
  35669,
  32467,
  0,
  799725,
  5883,
  2217,
  32292,
  355557,
  22179,
  1066,
  15704,
  610,
  37819,
  403626,
  83101,
  10989,
  311607,
  43394,
  72576,
  335450,
  85964,
  73734,
  105142,
  38292,
  0,
  181516,
  33959,
  611797,
  221838,
  5931,
  7666,
  1044,
  477173,
  13591,
  405,
  521,
  190653,
  184191,
  0,
  215,
  847195,
  22782,
  11912,
  27345,
  2572,
  0,
  566350,
  7,
  52302,
  26641,
  587826,
  127,
  2,
  44449,
  153198,
  14,
  926,
  285,
  0,
  938196,
  52255,
  9153,
  807,
  12548,
  358324,
  18521,
  104956,
  42738,
  116,
  135772,
  189554,
  38,
  54,
  36,
  89768,
  17170,
  75,
  34502,
  45489,
  172796,
  971810,
  16153,
  499280,
  1,
  879663,
  53830,
  186,
  539,
  242059,
  268,
  402,
  2732,
  68057,
  18463,
  198560,
  10068,
  591753,
  6116,
  699280,
  1,
  0,
  114258,
  277,
  149,
  283821,
  352561,
  88172,
  684476,
  3450,
  87,
  99936,
  3155,
  72983,
  31619,
  8832,
  58666,
  0,
  59023,
  306091,
  352150,
  255063,
  992708,
  23,
  4896,
  18165,
  424401,
  227613,
  5175,
  347,
  139846,
  11962,
  714,
  3501,
  82367,
  11110,
  10,
  12874,
  0,
  0,
  222712,
  169,
  123281,
  0,
  268149,
  101,
  17446,
  4262,
  489,
  0,
  30,
  0,
  277235,
  28,
  71,
  23,
  61219,
  953631,
  477548,
  662491,
  273,
  44787,
  4130,
  14483,
  470571,
  735977,
  406648,
  815898,
  5985,
  462696,
  937510,
  9,
  0,
  111727,
  93,
  331435,
  336402,
  78690,
  49,
  0,
  87422,
  1242,
  0,
  8783,
  8540,
  314,
  33411,
  805718,
  247,
  6870,
  523743,
  8323,
  612593,
  430,
  354048,
  264913,
  83,
  114063,
  202825,
  35202,
  32823,
  185554,
  85760,
  45159,
  5971,
  267733,
  4545,
  116,
  6910,
  24833,
  218,
  922362,
  221735,
  740,
  7112,
  31,
  15739,
  523589,
  4,
  95996,
  936,
  823951,
  0,
  88,
  160,
  375419,
  663627,
  3741,
  22896,
  114326,
  415962,
  880100,
  6222,
  18650,
  35524,
  195076,
  506,
  451640,
  541336,
  70903,
  3946,
  1,
  61765,
  1,
  2696,
  753129,
  289,
  225234,
  378692,
  1703,
  6751,
  1,
  820,
  7677,
  589,
  12412,
  317,
  69,
  226031,
  134523,
  318253,
  66677,
  111025,
  96,
  0,
  96,
  523528,
  1017,
  0,
  258740,
  420947,
  4600,
  400684,
  12174,
  11770,
  52,
  5959,
  82658,
  531787,
  202,
  548430,
  964,
  1054,
  34,
  96897,
  25445,
  47609,
  386052,
  97004,
  1935,
  30074,
  13458,
  494105,
  54,
  65575,
  594698,
  2340,
  20259,
  84,
  2774,
  534,
  972534,
  115057,
  0,
  11379,
  0,
  271,
  266305,
  132595,
  2,
  773561,
  52365,
  3585,
  351,
  148206,
  778964,
  149379,
  596,
  284914,
  2900,
  35596,
  1547,
  212027,
  8100,
  12248,
  3013,
  1814,
  183415,
  273633,
  15812,
  0,
  966680,
  14830,
  134309,
  0,
  416450,
  206611,
  816,
  82258,
  9873,
  3155,
  53485,
  779805,
  107690,
  254475,
  102504,
  72495,
  17301,
  472130,
  6895,
  245420,
  7299,
  110508,
  27776,
  246134,
  0,
  330853,
  0,
  271767,
  61886,
  24123,
  309681,
  58325,
  608865,
  20666,
  87349,
  229228,
  246,
  457768,
  5374,
  69643,
  148,
  618375,
  45236,
  352565,
  133904,
  152,
  10688,
  18,
  0,
  276036,
  493281,
  11156,
  12566,
  5762,
  113,
  24179,
  98,
  327,
  893,
  209180,
  140805,
  0,
  2341,
  66309,
  30305,
  630559,
  3682,
  152767,
  265822,
  142868,
  1535,
  728603,
  69081,
  353151,
  237995,
  1075,
  925071,
  86,
  6748,
  0,
  684186,
  735,
  13793,
  4790,
  73175,
  69677,
  367627,
  238650,
  303543,
  1,
  26059,
  21392,
  10,
  288609,
  0,
  76345,
  158496,
  7000,
  1865,
  20385,
  0,
  54213,
  9948,
  102667,
  6963,
  71,
  555744,
  5626,
  2512,
  1124,
  7171,
  628,
  29225,
  321687,
  61519,
  4,
  8352,
  9156,
};

char *pointers[NCYCLES];

int main(void)
{
  int r, i, j, sp, sq;
  char *p, *q, *ep, *eq;
  int ok;
  int err = 0;

  for ( r = 0 ; r < 4 ; r++ ) {
    for ( i = 0 ; i < NCYCLES ; i++ ) {
      pointers[i] = p = malloc(sp = sizes[i]);
      ep = p+sp;
      ok = 1;
      for ( j = 0 ; j < i ; j++ ) {
	q = pointers[j];
	sq = sizes[j];
	eq = q+sq;

	if ( (p < q && ep > q) || (p >= q && p < eq) ) {
	  ok = 0;
	  err = 1;
	  break;
	}
      }
      printf("Allocated %6d bytes at %p, ok = %d\n", sp, p, ok);

      if ( p )
	memset(p, 0xee, sp);	/* Poison this memory */
    }

    for ( i = 0 ; i < NCYCLES ; i++ ) {
      free(pointers[i]);
      printf("Freed %6d bytes at %p\n", sizes[i], pointers[i]);
    }
  }

  return err;
}
