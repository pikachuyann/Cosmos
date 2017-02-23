#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
using namespace std;
#include <string.h>
enum PosX_Color_Classe {
	Color_PosX_PosX_IC_0,
	Color_PosX_PosX_IC_1,
	Color_PosX_PosX_IC_2,
	Color_PosX_PosX_IC_3,
	Color_PosX_PosX_IC_4,
	Color_PosX_PosX_IC_5,
	Color_PosX_PosX_IC_6,
	Color_PosX_PosX_IC_7,
	Color_PosX_PosX_IC_8,
	Color_PosX_PosX_IC_9,
	Color_PosX_PosX_IC_10,
	Color_PosX_PosX_IC_11,
	Color_PosX_PosX_IC_12,
	Color_PosX_PosX_IC_13,
	Color_PosX_PosX_IC_14,
	Color_PosX_PosX_IC_15,
	Color_PosX_PosX_IC_16,
	Color_PosX_PosX_IC_17,
	Color_PosX_PosX_IC_18,
	Color_PosX_PosX_IC_19,
	Color_PosX_PosX_IC_20,
	Color_PosX_PosX_IC_21,
	Color_PosX_PosX_IC_22,
	Color_PosX_PosX_IC_23,
	Color_PosX_PosX_IC_24,
	Color_PosX_PosX_IC_25,
	Color_PosX_PosX_IC_26,
	Color_PosX_PosX_IC_27,
	Color_PosX_PosX_IC_28,
	Color_PosX_PosX_IC_29,
	Color_PosX_PosX_IC_30,
	Color_PosX_PosX_IC_31,
	Color_PosX_PosX_IC_32,
	Color_PosX_PosX_IC_33,
	Color_PosX_PosX_IC_34,
	Color_PosX_PosX_IC_35,
	Color_PosX_PosX_IC_36,
	Color_PosX_PosX_IC_37,
	Color_PosX_PosX_IC_38,
	Color_PosX_PosX_IC_39,
	Color_PosX_PosX_IC_40,
	Color_PosX_PosX_IC_41,
	Color_PosX_PosX_IC_42,
	Color_PosX_PosX_IC_43,
	Color_PosX_PosX_IC_44,
	Color_PosX_PosX_IC_45,
	Color_PosX_PosX_IC_46,
	Color_PosX_PosX_IC_47,
	Color_PosX_PosX_IC_48,
	Color_PosX_PosX_IC_49,
	Color_PosX_PosX_IC_50,
	Color_PosX_PosX_IC_51,
	Color_PosX_PosX_IC_52,
	Color_PosX_PosX_IC_53,
	Color_PosX_PosX_IC_54,
	Color_PosX_PosX_IC_55,
	Color_PosX_PosX_IC_56,
	Color_PosX_PosX_IC_57,
	Color_PosX_PosX_IC_58,
	Color_PosX_PosX_IC_59,
	Color_PosX_PosX_IC_60,
	Color_PosX_PosX_IC_61,
	Color_PosX_PosX_IC_62,
	Color_PosX_PosX_IC_63,
	Color_PosX_PosX_IC_64,
	Color_PosX_PosX_IC_65,
	Color_PosX_PosX_IC_66,
	Color_PosX_PosX_IC_67,
	Color_PosX_PosX_IC_68,
	Color_PosX_PosX_IC_69,
	Color_PosX_PosX_IC_70,
	Color_PosX_PosX_IC_71,
	Color_PosX_PosX_IC_72,
	Color_PosX_PosX_IC_73,
	Color_PosX_PosX_IC_74,
	Color_PosX_PosX_IC_75,
	Color_PosX_PosX_IC_76,
	Color_PosX_PosX_IC_77,
	Color_PosX_PosX_IC_78,
	Color_PosX_PosX_IC_79,
	Color_PosX_PosX_IC_80,
	Color_PosX_PosX_IC_81,
	Color_PosX_PosX_IC_82,
	Color_PosX_PosX_IC_83,
	Color_PosX_PosX_IC_84,
	Color_PosX_PosX_IC_85,
	Color_PosX_PosX_IC_86,
	Color_PosX_PosX_IC_87,
	Color_PosX_PosX_IC_88,
	Color_PosX_PosX_IC_89,
	Color_PosX_PosX_IC_90,
	Color_PosX_PosX_IC_91,
	Color_PosX_PosX_IC_92,
	Color_PosX_PosX_IC_93,
	Color_PosX_PosX_IC_94,
	Color_PosX_PosX_IC_95,
	Color_PosX_PosX_IC_96,
	Color_PosX_PosX_IC_97,
	Color_PosX_PosX_IC_98,
	Color_PosX_PosX_IC_99,
	Color_PosX_PosX_IC_100,
	Color_PosX_PosX_IC_101,
	Color_PosX_PosX_IC_102,
	Color_PosX_PosX_IC_103,
	Color_PosX_PosX_IC_104,
	Color_PosX_PosX_IC_105,
	Color_PosX_PosX_IC_106,
	Color_PosX_PosX_IC_107,
	Color_PosX_PosX_IC_108,
	Color_PosX_PosX_IC_109,
	Color_PosX_PosX_IC_110,
	Color_PosX_PosX_IC_111,
	Color_PosX_PosX_IC_112,
	Color_PosX_PosX_IC_113,
	Color_PosX_PosX_IC_114,
	Color_PosX_PosX_IC_115,
	Color_PosX_PosX_IC_116,
	Color_PosX_PosX_IC_117,
	Color_PosX_PosX_IC_118,
	Color_PosX_PosX_IC_119,
	Color_PosX_PosX_IC_120,
	Color_PosX_PosX_IC_121,
	Color_PosX_PosX_IC_122,
	Color_PosX_PosX_IC_123,
	Color_PosX_PosX_IC_124,
	Color_PosX_PosX_IC_125,
	Color_PosX_PosX_IC_126,
	Color_PosX_PosX_IC_127,
	Color_PosX_PosX_IC_128,
	Color_PosX_PosX_IC_129,
	Color_PosX_PosX_IC_130,
	Color_PosX_PosX_IC_131,
	Color_PosX_PosX_IC_132,
	Color_PosX_PosX_IC_133,
	Color_PosX_PosX_IC_134,
	Color_PosX_PosX_IC_135,
	Color_PosX_PosX_IC_136,
	Color_PosX_PosX_IC_137,
	Color_PosX_PosX_IC_138,
	Color_PosX_PosX_IC_139,
	Color_PosX_PosX_IC_140,
	Color_PosX_PosX_IC_141,
	Color_PosX_PosX_IC_142,
	Color_PosX_PosX_IC_143,
	Color_PosX_PosX_IC_144,
	Color_PosX_PosX_IC_145,
	Color_PosX_PosX_IC_146,
	Color_PosX_PosX_IC_147,
	Color_PosX_PosX_IC_148,
	Color_PosX_PosX_IC_149,
	Color_PosX_PosX_IC_150,
	Color_PosX_PosX_IC_151,
	Color_PosX_PosX_IC_152,
	Color_PosX_PosX_IC_153,
	Color_PosX_PosX_IC_154,
	Color_PosX_PosX_IC_155,
	Color_PosX_PosX_IC_156,
	Color_PosX_PosX_IC_157,
	Color_PosX_PosX_IC_158,
	Color_PosX_PosX_IC_159,
	Color_PosX_PosX_IC_160,
	Color_PosX_PosX_IC_161,
	Color_PosX_PosX_IC_162,
	Color_PosX_PosX_IC_163,
	Color_PosX_PosX_IC_164,
	Color_PosX_PosX_IC_165,
	Color_PosX_PosX_IC_166,
	Color_PosX_PosX_IC_167,
	Color_PosX_PosX_IC_168,
	Color_PosX_PosX_IC_169,
	Color_PosX_PosX_IC_170,
	Color_PosX_PosX_IC_171,
	Color_PosX_PosX_IC_172,
	Color_PosX_PosX_IC_173,
	Color_PosX_PosX_IC_174,
	Color_PosX_PosX_IC_175,
	Color_PosX_PosX_IC_176,
	Color_PosX_PosX_IC_177,
	Color_PosX_PosX_IC_178,
	Color_PosX_PosX_IC_179,
	Color_PosX_PosX_IC_180,
	Color_PosX_PosX_IC_181,
	Color_PosX_PosX_IC_182,
	Color_PosX_PosX_IC_183,
	Color_PosX_PosX_IC_184,
	Color_PosX_PosX_IC_185,
	Color_PosX_PosX_IC_186,
	Color_PosX_PosX_IC_187,
	Color_PosX_PosX_IC_188,
	Color_PosX_PosX_IC_189,
	Color_PosX_PosX_IC_190,
	Color_PosX_PosX_IC_191,
	Color_PosX_PosX_IC_192,
	Color_PosX_PosX_IC_193,
	Color_PosX_PosX_IC_194,
	Color_PosX_PosX_IC_195,
	Color_PosX_PosX_IC_196,
	Color_PosX_PosX_IC_197,
	Color_PosX_PosX_IC_198,
	Color_PosX_PosX_IC_199,
	Color_PosX_PosX_IC_200,
	Color_PosX_PosX_IC_201,
	Color_PosX_PosX_IC_202,
	Color_PosX_PosX_IC_203,
	Color_PosX_PosX_IC_204,
	Color_PosX_PosX_IC_205,
	Color_PosX_PosX_IC_206,
	Color_PosX_PosX_IC_207,
	Color_PosX_PosX_IC_208,
	Color_PosX_PosX_IC_209,
	Color_PosX_PosX_IC_210,
	Color_PosX_PosX_IC_211,
	Color_PosX_PosX_IC_212,
	Color_PosX_PosX_IC_213,
	Color_PosX_PosX_IC_214,
	Color_PosX_PosX_IC_215,
	Color_PosX_PosX_IC_216,
	Color_PosX_PosX_IC_217,
	Color_PosX_PosX_IC_218,
	Color_PosX_PosX_IC_219,
	Color_PosX_PosX_IC_220,
	Color_PosX_PosX_IC_221,
	Color_PosX_PosX_IC_222,
	Color_PosX_PosX_IC_223,
	Color_PosX_PosX_IC_224,
	Color_PosX_PosX_IC_225,
	Color_PosX_PosX_IC_226,
	Color_PosX_PosX_IC_227,
	Color_PosX_PosX_IC_228,
	Color_PosX_PosX_IC_229,
	Color_PosX_PosX_IC_230,
	Color_PosX_PosX_IC_231,
	Color_PosX_PosX_IC_232,
	Color_PosX_PosX_IC_233,
	Color_PosX_PosX_IC_234,
	Color_PosX_PosX_IC_235,
	Color_PosX_PosX_IC_236,
	Color_PosX_PosX_IC_237,
	Color_PosX_PosX_IC_238,
	Color_PosX_PosX_IC_239,
	Color_PosX_PosX_IC_240,
	Color_PosX_PosX_IC_241,
	Color_PosX_PosX_IC_242,
	Color_PosX_PosX_IC_243,
	Color_PosX_PosX_IC_244,
	Color_PosX_PosX_IC_245,
	Color_PosX_PosX_IC_246,
	Color_PosX_PosX_IC_247,
	Color_PosX_PosX_IC_248,
	Color_PosX_PosX_IC_249,
	Color_PosX_PosX_IC_250,
	Color_PosX_PosX_IC_251,
	Color_PosX_PosX_IC_252,
	Color_PosX_PosX_IC_253,
	Color_PosX_PosX_IC_254,
	Color_PosX_PosX_IC_255,
	Color_PosX_PosX_IC_256,
	Color_PosX_PosX_IC_257,
	Color_PosX_PosX_IC_258,
	Color_PosX_PosX_IC_259,
	Color_PosX_PosX_IC_260,
	Color_PosX_PosX_IC_261,
	Color_PosX_PosX_IC_262,
	Color_PosX_PosX_IC_263,
	Color_PosX_PosX_IC_264,
	Color_PosX_PosX_IC_265,
	Color_PosX_PosX_IC_266,
	Color_PosX_PosX_IC_267,
	Color_PosX_PosX_IC_268,
	Color_PosX_PosX_IC_269,
	Color_PosX_PosX_IC_270,
	Color_PosX_PosX_IC_271,
	Color_PosX_PosX_IC_272,
	Color_PosX_PosX_IC_273,
	Color_PosX_PosX_IC_274,
	Color_PosX_PosX_IC_275,
	Color_PosX_PosX_IC_276,
	Color_PosX_PosX_IC_277,
	Color_PosX_PosX_IC_278,
	Color_PosX_PosX_IC_279,
	Color_PosX_PosX_IC_280,
	Color_PosX_PosX_IC_281,
	Color_PosX_PosX_IC_282,
	Color_PosX_PosX_IC_283,
	Color_PosX_PosX_IC_284,
	Color_PosX_PosX_IC_285,
	Color_PosX_PosX_IC_286,
	Color_PosX_PosX_IC_287,
	Color_PosX_PosX_IC_288,
	Color_PosX_PosX_IC_289,
	Color_PosX_PosX_IC_290,
	Color_PosX_PosX_IC_291,
	Color_PosX_PosX_IC_292,
	Color_PosX_PosX_IC_293,
	Color_PosX_PosX_IC_294,
	Color_PosX_PosX_IC_295,
	Color_PosX_PosX_IC_296,
	Color_PosX_PosX_IC_297,
	Color_PosX_PosX_IC_298,
	Color_PosX_PosX_IC_299,
	Color_PosX_PosX_IC_300,
	Color_PosX_PosX_IC_301,
	Color_PosX_PosX_IC_302,
	Color_PosX_PosX_IC_303,
	Color_PosX_PosX_IC_304,
	Color_PosX_PosX_IC_305,
	Color_PosX_PosX_IC_306,
	Color_PosX_PosX_IC_307,
	Color_PosX_PosX_IC_308,
	Color_PosX_PosX_IC_309,
	Color_PosX_PosX_IC_310,
	Color_PosX_PosX_IC_311,
	Color_PosX_PosX_IC_312,
	Color_PosX_PosX_IC_313,
	Color_PosX_PosX_IC_314,
	Color_PosX_PosX_IC_315,
	Color_PosX_PosX_IC_316,
	Color_PosX_PosX_IC_317,
	Color_PosX_PosX_IC_318,
	Color_PosX_PosX_IC_319,
	Color_PosX_PosX_IC_320,
	Color_PosX_PosX_IC_321,
	Color_PosX_PosX_IC_322,
	Color_PosX_PosX_IC_323,
	Color_PosX_PosX_IC_324,
	Color_PosX_PosX_IC_325,
	Color_PosX_PosX_IC_326,
	Color_PosX_PosX_IC_327,
	Color_PosX_PosX_IC_328,
	Color_PosX_PosX_IC_329,
	Color_PosX_PosX_IC_330,
	Color_PosX_PosX_IC_331,
	Color_PosX_PosX_IC_332,
	Color_PosX_PosX_IC_333,
	Color_PosX_PosX_IC_334,
	Color_PosX_PosX_IC_335,
	Color_PosX_PosX_IC_336,
	Color_PosX_PosX_IC_337,
	Color_PosX_PosX_IC_338,
	Color_PosX_PosX_IC_339,
	Color_PosX_PosX_IC_340,
	Color_PosX_PosX_IC_341,
	Color_PosX_PosX_IC_342,
	Color_PosX_PosX_IC_343,
	Color_PosX_PosX_IC_344,
	Color_PosX_PosX_IC_345,
	Color_PosX_PosX_IC_346,
	Color_PosX_PosX_IC_347,
	Color_PosX_PosX_IC_348,
	Color_PosX_PosX_IC_349,
	Color_PosX_PosX_IC_350,
	Color_PosX_PosX_IC_351,
	Color_PosX_PosX_IC_352,
	Color_PosX_PosX_IC_353,
	Color_PosX_PosX_IC_354,
	Color_PosX_PosX_IC_355,
	Color_PosX_PosX_IC_356,
	Color_PosX_PosX_IC_357,
	Color_PosX_PosX_IC_358,
	Color_PosX_PosX_IC_359,
	Color_PosX_PosX_IC_360,
	Color_PosX_PosX_IC_361,
	Color_PosX_PosX_IC_362,
	Color_PosX_PosX_IC_363,
	Color_PosX_PosX_IC_364,
	Color_PosX_PosX_IC_365,
	Color_PosX_PosX_IC_366,
	Color_PosX_PosX_IC_367,
	Color_PosX_PosX_IC_368,
	Color_PosX_PosX_IC_369,
	Color_PosX_PosX_IC_370,
	Color_PosX_PosX_IC_371,
	Color_PosX_PosX_IC_372,
	Color_PosX_PosX_IC_373,
	Color_PosX_PosX_IC_374,
	Color_PosX_PosX_IC_375,
	Color_PosX_PosX_IC_376,
	Color_PosX_PosX_IC_377,
	Color_PosX_PosX_IC_378,
	Color_PosX_PosX_IC_379,
	Color_PosX_PosX_IC_380,
	Color_PosX_PosX_IC_381,
	Color_PosX_PosX_IC_382,
	Color_PosX_PosX_IC_383,
	Color_PosX_PosX_IC_384,
	Color_PosX_PosX_IC_385,
	Color_PosX_PosX_IC_386,
	Color_PosX_PosX_IC_387,
	Color_PosX_PosX_IC_388,
	Color_PosX_PosX_IC_389,
	Color_PosX_PosX_IC_390,
	Color_PosX_PosX_IC_391,
	Color_PosX_PosX_IC_392,
	Color_PosX_PosX_IC_393,
	Color_PosX_PosX_IC_394,
	Color_PosX_PosX_IC_395,
	Color_PosX_PosX_IC_396,
	Color_PosX_PosX_IC_397,
	Color_PosX_PosX_IC_398,
	Color_PosX_PosX_IC_399,
	Color_PosX_PosX_IC_400,
	Color_PosX_PosX_IC_401,
	Color_PosX_PosX_IC_402,
	Color_PosX_PosX_IC_403,
	Color_PosX_PosX_IC_404,
	Color_PosX_PosX_IC_405,
	Color_PosX_PosX_IC_406,
	Color_PosX_PosX_IC_407,
	Color_PosX_PosX_IC_408,
	Color_PosX_PosX_IC_409,
	Color_PosX_PosX_IC_410,
	Color_PosX_PosX_IC_411,
	Color_PosX_PosX_IC_412,
	Color_PosX_PosX_IC_413,
	Color_PosX_PosX_IC_414,
	Color_PosX_PosX_IC_415,
	Color_PosX_PosX_IC_416,
	Color_PosX_PosX_IC_417,
	Color_PosX_PosX_IC_418,
	Color_PosX_PosX_IC_419,
	Color_PosX_PosX_IC_420,
	Color_PosX_PosX_IC_421,
	Color_PosX_PosX_IC_422,
	Color_PosX_PosX_IC_423,
	Color_PosX_PosX_IC_424,
	Color_PosX_PosX_IC_425,
	Color_PosX_PosX_IC_426,
	Color_PosX_PosX_IC_427,
	Color_PosX_PosX_IC_428,
	Color_PosX_PosX_IC_429,
	Color_PosX_PosX_IC_430,
	Color_PosX_PosX_IC_431,
	Color_PosX_PosX_IC_432,
	Color_PosX_PosX_IC_433,
	Color_PosX_PosX_IC_434,
	Color_PosX_PosX_IC_435,
	Color_PosX_PosX_IC_436,
	Color_PosX_PosX_IC_437,
	Color_PosX_PosX_IC_438,
	Color_PosX_PosX_IC_439,
	Color_PosX_PosX_IC_440,
	Color_PosX_PosX_IC_441,
	Color_PosX_PosX_IC_442,
	Color_PosX_PosX_IC_443,
	Color_PosX_PosX_IC_444,
	Color_PosX_PosX_IC_445,
	Color_PosX_PosX_IC_446,
	Color_PosX_PosX_IC_447,
	Color_PosX_PosX_IC_448,
	Color_PosX_PosX_IC_449,
	Color_PosX_PosX_IC_450,
	Color_PosX_PosX_IC_451,
	Color_PosX_PosX_IC_452,
	Color_PosX_PosX_IC_453,
	Color_PosX_PosX_IC_454,
	Color_PosX_PosX_IC_455,
	Color_PosX_PosX_IC_456,
	Color_PosX_PosX_IC_457,
	Color_PosX_PosX_IC_458,
	Color_PosX_PosX_IC_459,
	Color_PosX_PosX_IC_460,
	Color_PosX_PosX_IC_461,
	Color_PosX_PosX_IC_462,
	Color_PosX_PosX_IC_463,
	Color_PosX_PosX_IC_464,
	Color_PosX_PosX_IC_465,
	Color_PosX_PosX_IC_466,
	Color_PosX_PosX_IC_467,
	Color_PosX_PosX_IC_468,
	Color_PosX_PosX_IC_469,
	Color_PosX_PosX_IC_470,
	Color_PosX_PosX_IC_471,
	Color_PosX_PosX_IC_472,
	Color_PosX_PosX_IC_473,
	Color_PosX_PosX_IC_474,
	Color_PosX_PosX_IC_475,
	Color_PosX_PosX_IC_476,
	Color_PosX_PosX_IC_477,
	Color_PosX_PosX_IC_478,
	Color_PosX_PosX_IC_479,
	Color_PosX_PosX_IC_480,
	Color_PosX_PosX_IC_481,
	Color_PosX_PosX_IC_482,
	Color_PosX_PosX_IC_483,
	Color_PosX_PosX_IC_484,
	Color_PosX_PosX_IC_485,
	Color_PosX_PosX_IC_486,
	Color_PosX_PosX_IC_487,
	Color_PosX_PosX_IC_488,
	Color_PosX_PosX_IC_489,
	Color_PosX_PosX_IC_490,
	Color_PosX_PosX_IC_491,
	Color_PosX_PosX_IC_492,
	Color_PosX_PosX_IC_493,
	Color_PosX_PosX_IC_494,
	Color_PosX_PosX_IC_495,
	Color_PosX_PosX_IC_496,
	Color_PosX_PosX_IC_497,
	Color_PosX_PosX_IC_498,
	Color_PosX_PosX_IC_499,
	Color_PosX_PosX_IC_500,
	Color_PosX_Total,
	Color_PosX_All
};
extern const char *Color_PosX_names[];
struct contains_PosX_Color_Classe{
	virtual void apply_perm(PosX_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(PosX_Color_Classe,int,int) const =0;
};
enum PosY_Color_Classe {
	Color_PosY_PosY_IC_0,
	Color_PosY_PosY_IC_1,
	Color_PosY_Total,
	Color_PosY_All
};
extern const char *Color_PosY_names[];
struct contains_PosY_Color_Classe{
	virtual void apply_perm(PosY_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(PosY_Color_Classe,int,int) const =0;
};
enum VitX_Color_Classe {
	Color_VitX_VitX_IC_0,
	Color_VitX_VitX_IC_1,
	Color_VitX_VitX_IC_2,
	Color_VitX_Total,
	Color_VitX_All
};
extern const char *Color_VitX_names[];
struct contains_VitX_Color_Classe{
	virtual void apply_perm(VitX_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(VitX_Color_Classe,int,int) const =0;
};
enum VitY_Color_Classe {
	Color_VitY_VitY_IC_0,
	Color_VitY_VitY_IC_1,
	Color_VitY_Total,
	Color_VitY_All
};
extern const char *Color_VitY_names[];
struct contains_VitY_Color_Classe{
	virtual void apply_perm(VitY_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(VitY_Color_Classe,int,int) const =0;
};
enum AccX_Color_Classe {
	Color_AccX_AccX_IC_0,
	Color_AccX_AccX_IC_1,
	Color_AccX_Total,
	Color_AccX_All
};
extern const char *Color_AccX_names[];
struct contains_AccX_Color_Classe{
	virtual void apply_perm(AccX_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(AccX_Color_Classe,int,int) const =0;
};
enum AccY_Color_Classe {
	Color_AccY_AccY_IC_0,
	Color_AccY_AccY_IC_1,
	Color_AccY_Total,
	Color_AccY_All
};
extern const char *Color_AccY_names[];
struct contains_AccY_Color_Classe{
	virtual void apply_perm(AccY_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(AccY_Color_Classe,int,int) const =0;
};
enum Jeton_Color_Classe {
	Color_Jeton_Jeton_IC_1,
	Color_Jeton_Total,
	Color_Jeton_All
};
extern const char *Color_Jeton_names[];
struct contains_Jeton_Color_Classe{
	virtual void apply_perm(Jeton_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(Jeton_Color_Classe,int,int) const =0;
};
#include "marking.hpp"
#include "markingTemplate.hpp"

struct PosX_Token{
	PosX_Color_Classe c0;
	int mult;
	PosX_Token(  PosX_Color_Classe cv0 = (PosX_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	PosX_Token( const PosX_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	PosX_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosX_Color_Classe)(Color_PosX_Total - 1) ){ c0 = (PosX_Color_Classe)(c0+ 1); return;};
c0 = (PosX_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosX_names[c0] << ">";
	}
	PosX_Token next(int i)const {
		PosX_Token x((PosX_Color_Classe)((c0 +i) % Color_PosX_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (PosX_Color_Classe)(Color_PosX_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const PosX_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< PosX_Token> PosX_Domain;

struct PosY_Token{
	PosY_Color_Classe c0;
	int mult;
	PosY_Token(  PosY_Color_Classe cv0 = (PosY_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	PosY_Token( const PosY_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	PosY_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosY_Color_Classe)(Color_PosY_Total - 1) ){ c0 = (PosY_Color_Classe)(c0+ 1); return;};
c0 = (PosY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosY_names[c0] << ">";
	}
	PosY_Token next(int i)const {
		PosY_Token x((PosY_Color_Classe)((c0 +i) % Color_PosY_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (PosY_Color_Classe)(Color_PosY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const PosY_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< PosY_Token> PosY_Domain;

struct VitX_Token{
	VitX_Color_Classe c0;
	int mult;
	VitX_Token(  VitX_Color_Classe cv0 = (VitX_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	VitX_Token( const VitX_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	VitX_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (VitX_Color_Classe)(Color_VitX_Total - 1) ){ c0 = (VitX_Color_Classe)(c0+ 1); return;};
c0 = (VitX_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_VitX_names[c0] << ">";
	}
	VitX_Token next(int i)const {
		VitX_Token x((VitX_Color_Classe)((c0 +i) % Color_VitX_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (VitX_Color_Classe)(Color_VitX_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const VitX_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< VitX_Token> VitX_Domain;

struct VitY_Token{
	VitY_Color_Classe c0;
	int mult;
	VitY_Token(  VitY_Color_Classe cv0 = (VitY_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	VitY_Token( const VitY_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	VitY_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (VitY_Color_Classe)(Color_VitY_Total - 1) ){ c0 = (VitY_Color_Classe)(c0+ 1); return;};
c0 = (VitY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_VitY_names[c0] << ">";
	}
	VitY_Token next(int i)const {
		VitY_Token x((VitY_Color_Classe)((c0 +i) % Color_VitY_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (VitY_Color_Classe)(Color_VitY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const VitY_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< VitY_Token> VitY_Domain;

struct AccX_Token{
	AccX_Color_Classe c0;
	int mult;
	AccX_Token(  AccX_Color_Classe cv0 = (AccX_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	AccX_Token( const AccX_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	AccX_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (AccX_Color_Classe)(Color_AccX_Total - 1) ){ c0 = (AccX_Color_Classe)(c0+ 1); return;};
c0 = (AccX_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_AccX_names[c0] << ">";
	}
	AccX_Token next(int i)const {
		AccX_Token x((AccX_Color_Classe)((c0 +i) % Color_AccX_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (AccX_Color_Classe)(Color_AccX_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const AccX_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< AccX_Token> AccX_Domain;

struct AccY_Token{
	AccY_Color_Classe c0;
	int mult;
	AccY_Token(  AccY_Color_Classe cv0 = (AccY_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	AccY_Token( const AccY_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	AccY_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (AccY_Color_Classe)(Color_AccY_Total - 1) ){ c0 = (AccY_Color_Classe)(c0+ 1); return;};
c0 = (AccY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_AccY_names[c0] << ">";
	}
	AccY_Token next(int i)const {
		AccY_Token x((AccY_Color_Classe)((c0 +i) % Color_AccY_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (AccY_Color_Classe)(Color_AccY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const AccY_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< AccY_Token> AccY_Domain;

struct Jeton_Token{
	Jeton_Color_Classe c0;
	int mult;
	Jeton_Token(  Jeton_Color_Classe cv0 = (Jeton_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	Jeton_Token( const Jeton_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	Jeton_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (Jeton_Color_Classe)(Color_Jeton_Total - 1) ){ c0 = (Jeton_Color_Classe)(c0+ 1); return;};
c0 = (Jeton_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_Jeton_names[c0] << ">";
	}
	Jeton_Token next(int i)const {
		Jeton_Token x((Jeton_Color_Classe)((c0 +i) % Color_Jeton_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (Jeton_Color_Classe)(Color_Jeton_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const Jeton_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< Jeton_Token> Jeton_Domain;

struct Vehicle_Token{
	PosX_Color_Classe c0;
	PosY_Color_Classe c1;
	VitX_Color_Classe c2;
	VitY_Color_Classe c3;
	int mult;
	Vehicle_Token(  PosX_Color_Classe cv0 = (PosX_Color_Classe)0,  PosY_Color_Classe cv1 = (PosY_Color_Classe)0,  VitX_Color_Classe cv2 = (VitX_Color_Classe)0,  VitY_Color_Classe cv3 = (VitY_Color_Classe)0, int v =1) {
		c0= cv0;
		c1= cv1;
		c2= cv2;
		c3= cv3;
		mult = v;
	}
	Vehicle_Token( const PosX_Token& cv0, const PosY_Token& cv1, const VitX_Token& cv2, const VitY_Token& cv3, int v =1) {
		c0= cv0.c0;
		c1= cv1.c0;
		c2= cv2.c0;
		c3= cv3.c0;
		mult = v;
	}
	Vehicle_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosX_Color_Classe)(Color_PosX_Total - 1) ){ c0 = (PosX_Color_Classe)(c0+ 1); return;};
c0 = (PosX_Color_Classe)(0);
		if( c1< (PosY_Color_Classe)(Color_PosY_Total - 1) ){ c1 = (PosY_Color_Classe)(c1+ 1); return;};
c1 = (PosY_Color_Classe)(0);
		if( c2< (VitX_Color_Classe)(Color_VitX_Total - 1) ){ c2 = (VitX_Color_Classe)(c2+ 1); return;};
c2 = (VitX_Color_Classe)(0);
		if( c3< (VitY_Color_Classe)(Color_VitY_Total - 1) ){ c3 = (VitY_Color_Classe)(c3+ 1); return;};
c3 = (VitY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosX_names[c0]<< " , " <<  Color_PosY_names[c1]<< " , " <<  Color_VitX_names[c2]<< " , " <<  Color_VitY_names[c3] << ">";
	}
	bool islast()const {
		return ( c0== (PosX_Color_Classe)(Color_PosX_Total -1)  &&  c1== (PosY_Color_Classe)(Color_PosY_Total -1)  &&  c2== (VitX_Color_Classe)(Color_VitX_Total -1)  &&  c3== (VitY_Color_Classe)(Color_VitY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const Vehicle_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		if (c1 < tok.c1) { return true; }
		if (c1 > tok.c1) { return false; }
		if (c2 < tok.c2) { return true; }
		if (c2 > tok.c2) { return false; }
		if (c3 < tok.c3) { return true; }
		if (c3 > tok.c3) { return false; }
		return false;
	}
};
typedef DomainGen< Vehicle_Token> Vehicle_Domain;

struct SelfVehicle_Token{
	PosX_Color_Classe c0;
	PosY_Color_Classe c1;
	VitX_Color_Classe c2;
	VitY_Color_Classe c3;
	AccX_Color_Classe c4;
	AccY_Color_Classe c5;
	int mult;
	SelfVehicle_Token(  PosX_Color_Classe cv0 = (PosX_Color_Classe)0,  PosY_Color_Classe cv1 = (PosY_Color_Classe)0,  VitX_Color_Classe cv2 = (VitX_Color_Classe)0,  VitY_Color_Classe cv3 = (VitY_Color_Classe)0,  AccX_Color_Classe cv4 = (AccX_Color_Classe)0,  AccY_Color_Classe cv5 = (AccY_Color_Classe)0, int v =1) {
		c0= cv0;
		c1= cv1;
		c2= cv2;
		c3= cv3;
		c4= cv4;
		c5= cv5;
		mult = v;
	}
	SelfVehicle_Token( const PosX_Token& cv0, const PosY_Token& cv1, const VitX_Token& cv2, const VitY_Token& cv3, const AccX_Token& cv4, const AccY_Token& cv5, int v =1) {
		c0= cv0.c0;
		c1= cv1.c0;
		c2= cv2.c0;
		c3= cv3.c0;
		c4= cv4.c0;
		c5= cv5.c0;
		mult = v;
	}
	SelfVehicle_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosX_Color_Classe)(Color_PosX_Total - 1) ){ c0 = (PosX_Color_Classe)(c0+ 1); return;};
c0 = (PosX_Color_Classe)(0);
		if( c1< (PosY_Color_Classe)(Color_PosY_Total - 1) ){ c1 = (PosY_Color_Classe)(c1+ 1); return;};
c1 = (PosY_Color_Classe)(0);
		if( c2< (VitX_Color_Classe)(Color_VitX_Total - 1) ){ c2 = (VitX_Color_Classe)(c2+ 1); return;};
c2 = (VitX_Color_Classe)(0);
		if( c3< (VitY_Color_Classe)(Color_VitY_Total - 1) ){ c3 = (VitY_Color_Classe)(c3+ 1); return;};
c3 = (VitY_Color_Classe)(0);
		if( c4< (AccX_Color_Classe)(Color_AccX_Total - 1) ){ c4 = (AccX_Color_Classe)(c4+ 1); return;};
c4 = (AccX_Color_Classe)(0);
		if( c5< (AccY_Color_Classe)(Color_AccY_Total - 1) ){ c5 = (AccY_Color_Classe)(c5+ 1); return;};
c5 = (AccY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosX_names[c0]<< " , " <<  Color_PosY_names[c1]<< " , " <<  Color_VitX_names[c2]<< " , " <<  Color_VitY_names[c3]<< " , " <<  Color_AccX_names[c4]<< " , " <<  Color_AccY_names[c5] << ">";
	}
	bool islast()const {
		return ( c0== (PosX_Color_Classe)(Color_PosX_Total -1)  &&  c1== (PosY_Color_Classe)(Color_PosY_Total -1)  &&  c2== (VitX_Color_Classe)(Color_VitX_Total -1)  &&  c3== (VitY_Color_Classe)(Color_VitY_Total -1)  &&  c4== (AccX_Color_Classe)(Color_AccX_Total -1)  &&  c5== (AccY_Color_Classe)(Color_AccY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const SelfVehicle_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		if (c1 < tok.c1) { return true; }
		if (c1 > tok.c1) { return false; }
		if (c2 < tok.c2) { return true; }
		if (c2 > tok.c2) { return false; }
		if (c3 < tok.c3) { return true; }
		if (c3 > tok.c3) { return false; }
		if (c4 < tok.c4) { return true; }
		if (c4 > tok.c4) { return false; }
		if (c5 < tok.c5) { return true; }
		if (c5 > tok.c5) { return false; }
		return false;
	}
};
typedef DomainGen< SelfVehicle_Token> SelfVehicle_Domain;
class abstractBindingImpl {
public:
	PosX_Token xs;
	PosX_Token x;
	PosY_Token ys;
	PosY_Token y;
	VitX_Token dxs;
	VitX_Token dx;
	VitY_Token dys;
	VitY_Token dy;
	AccX_Token ddx;
	AccY_Token ddy;
	Jeton_Token j;
};
class abstractMarkingImpl {
public:
	SelfVehicle_Domain _PL_selfVehicle;
	Jeton_Domain _PL_simstep1;
	Jeton_Domain _PL_simstep2;
	Jeton_Domain _PL_simstep3;
	Jeton_Domain _PL_simstep4;
	Jeton_Domain _PL_initGenere;
	Vehicle_Domain _PL_inProcess;
	Vehicle_Domain _PL_otherVehicles;
	int _PL_PosFinale;
	PosX_Domain _PL_PositionMax;
	PosX_Domain xs;
	PosX_Domain x;
	PosY_Domain ys;
	PosY_Domain y;
	VitX_Domain dxs;
	VitX_Domain dx;
	VitY_Domain dys;
	VitY_Domain dy;
	AccX_Domain ddx;
	AccY_Domain ddy;
	Jeton_Domain j;
};
class abstractBindingIteratorImpl {
public:
	std::map<SelfVehicle_Token, unsigned int>::const_iterator ItPl_selfVehicle;
	std::map<Jeton_Token, unsigned int>::const_iterator ItPl_simstep1;
	std::map<Jeton_Token, unsigned int>::const_iterator ItPl_simstep2;
	std::map<Jeton_Token, unsigned int>::const_iterator ItPl_simstep3;
	std::map<Jeton_Token, unsigned int>::const_iterator ItPl_simstep4;
	std::map<Jeton_Token, unsigned int>::const_iterator ItPl_initGenere;
	std::map<Vehicle_Token, unsigned int>::const_iterator ItPl_inProcess;
	std::map<Vehicle_Token, unsigned int>::const_iterator ItPl_otherVehicles;
	std::map<PosX_Token, unsigned int>::const_iterator ItPl_PositionMax;
	size_t ItVar_xs = 0;
	bool IsDefItVar_xs = false;
	size_t ItVar_x = 0;
	bool IsDefItVar_x = false;
	size_t ItVar_ys = 0;
	bool IsDefItVar_ys = false;
	size_t ItVar_y = 0;
	bool IsDefItVar_y = false;
	size_t ItVar_dxs = 0;
	bool IsDefItVar_dxs = false;
	size_t ItVar_dx = 0;
	bool IsDefItVar_dx = false;
	size_t ItVar_dys = 0;
	bool IsDefItVar_dys = false;
	size_t ItVar_dy = 0;
	bool IsDefItVar_dy = false;
	size_t ItVar_ddx = 0;
	bool IsDefItVar_ddx = false;
	size_t ItVar_ddy = 0;
	bool IsDefItVar_ddy = false;
	size_t ItVar_j = 0;
	bool IsDefItVar_j = false;
	bool foundnint = true;
	void reset(abstractMarkingImpl& m);
private:
	bool nextInterieur(size_t& t, abstractMarkingImpl& m) {
	switch (t){
		case 6:	//updOther

			if (m._PL_inProcess.tokens.empty()) {
				return false;
			}
			if (not (ItPl_inProcess == m._PL_inProcess.tokens.end())) { 
				ItPl_inProcess++;
				if (not (ItPl_inProcess == m._PL_inProcess.tokens.end())) { 
					return true;
				} else {
				ItPl_inProcess = m._PL_inProcess.tokens.begin();
				}
			}
			if (m._PL_simstep2.tokens.empty()) {
				return false;
			}
			if (not (ItPl_simstep2 == m._PL_simstep2.tokens.end())) { 
				ItPl_simstep2++;
				if (not (ItPl_simstep2 == m._PL_simstep2.tokens.end())) { 
					return true;
				} else {
				ItPl_simstep2 = m._PL_simstep2.tokens.begin();
				}
			}
			return false;
		break;
		case 2:	//simstepA

			if (m._PL_initGenere.tokens.empty()) {
				return false;
			}
			if (not (ItPl_initGenere == m._PL_initGenere.tokens.end())) { 
				ItPl_initGenere++;
				if (not (ItPl_initGenere == m._PL_initGenere.tokens.end())) { 
					return true;
				} else {
				ItPl_initGenere = m._PL_initGenere.tokens.begin();
				}
			}
			return false;
		break;
		case 8:	//exit

			if (m._PL_otherVehicles.tokens.empty()) {
				return false;
			}
			if (not (ItPl_otherVehicles == m._PL_otherVehicles.tokens.end())) { 
				ItPl_otherVehicles++;
				if (not (ItPl_otherVehicles == m._PL_otherVehicles.tokens.end())) { 
					return true;
				} else {
				ItPl_otherVehicles = m._PL_otherVehicles.tokens.begin();
				}
			}
			if (m._PL_PositionMax.tokens.empty()) {
				return false;
			}
			if (not (ItPl_PositionMax == m._PL_PositionMax.tokens.end())) { 
				ItPl_PositionMax++;
				if (not (ItPl_PositionMax == m._PL_PositionMax.tokens.end())) { 
					return true;
				} else {
				ItPl_PositionMax = m._PL_PositionMax.tokens.begin();
				}
			}
			return false;
		break;
		case 5:	//randOther

			if (m._PL_otherVehicles.tokens.empty()) {
				return false;
			}
			if (not (ItPl_otherVehicles == m._PL_otherVehicles.tokens.end())) { 
				ItPl_otherVehicles++;
				if (not (ItPl_otherVehicles == m._PL_otherVehicles.tokens.end())) { 
					return true;
				} else {
				ItPl_otherVehicles = m._PL_otherVehicles.tokens.begin();
				}
			}
			if (m._PL_simstep1.tokens.empty()) {
				return false;
			}
			if (not (ItPl_simstep1 == m._PL_simstep1.tokens.end())) { 
				ItPl_simstep1++;
				if (not (ItPl_simstep1 == m._PL_simstep1.tokens.end())) { 
					return true;
				} else {
				ItPl_simstep1 = m._PL_simstep1.tokens.begin();
				}
			}
			return false;
		break;
		case 9:	//end

			if (m._PL_selfVehicle.tokens.empty()) {
				return false;
			}
			if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
				ItPl_selfVehicle++;
				if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
					return true;
				} else {
				ItPl_selfVehicle = m._PL_selfVehicle.tokens.begin();
				}
			}
			if (m._PL_PositionMax.tokens.empty()) {
				return false;
			}
			if (not (ItPl_PositionMax == m._PL_PositionMax.tokens.end())) { 
				ItPl_PositionMax++;
				if (not (ItPl_PositionMax == m._PL_PositionMax.tokens.end())) { 
					return true;
				} else {
				ItPl_PositionMax = m._PL_PositionMax.tokens.begin();
				}
			}
			return false;
		break;
		case 10:	//collision

			if (m._PL_selfVehicle.tokens.empty()) {
				return false;
			}
			if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
				ItPl_selfVehicle++;
				if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
					return true;
				} else {
				ItPl_selfVehicle = m._PL_selfVehicle.tokens.begin();
				}
			}
			if (m._PL_otherVehicles.tokens.empty()) {
				return false;
			}
			if (not (ItPl_otherVehicles == m._PL_otherVehicles.tokens.end())) { 
				ItPl_otherVehicles++;
				if (not (ItPl_otherVehicles == m._PL_otherVehicles.tokens.end())) { 
					return true;
				} else {
				ItPl_otherVehicles = m._PL_otherVehicles.tokens.begin();
				}
			}
			return false;
		break;
		case 0:	//updateSelf

			if (m._PL_selfVehicle.tokens.empty()) {
				return false;
			}
			if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
				ItPl_selfVehicle++;
				if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
					return true;
				} else {
				ItPl_selfVehicle = m._PL_selfVehicle.tokens.begin();
				}
			}
			if (m._PL_simstep3.tokens.empty()) {
				return false;
			}
			if (not (ItPl_simstep3 == m._PL_simstep3.tokens.end())) { 
				ItPl_simstep3++;
				if (not (ItPl_simstep3 == m._PL_simstep3.tokens.end())) { 
					return true;
				} else {
				ItPl_simstep3 = m._PL_simstep3.tokens.begin();
				}
			}
			return false;
		break;
		case 1:	//lightController

			if (m._PL_selfVehicle.tokens.empty()) {
				return false;
			}
			if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
				ItPl_selfVehicle++;
				if (not (ItPl_selfVehicle == m._PL_selfVehicle.tokens.end())) { 
					return true;
				} else {
				ItPl_selfVehicle = m._PL_selfVehicle.tokens.begin();
				}
			}
			if (m._PL_simstep4.tokens.empty()) {
				return false;
			}
			if (not (ItPl_simstep4 == m._PL_simstep4.tokens.end())) { 
				ItPl_simstep4++;
				if (not (ItPl_simstep4 == m._PL_simstep4.tokens.end())) { 
					return true;
				} else {
				ItPl_simstep4 = m._PL_simstep4.tokens.begin();
				}
			}
			return false;
		break;
		case 3:	//simstepB

			if (m._PL_simstep1.tokens.empty()) {
				return false;
			}
			if (not (ItPl_simstep1 == m._PL_simstep1.tokens.end())) { 
				ItPl_simstep1++;
				if (not (ItPl_simstep1 == m._PL_simstep1.tokens.end())) { 
					return true;
				} else {
				ItPl_simstep1 = m._PL_simstep1.tokens.begin();
				}
			}
			return false;
		break;
		case 4:	//simstepC

			if (m._PL_simstep2.tokens.empty()) {
				return false;
			}
			if (not (ItPl_simstep2 == m._PL_simstep2.tokens.end())) { 
				ItPl_simstep2++;
				if (not (ItPl_simstep2 == m._PL_simstep2.tokens.end())) { 
					return true;
				} else {
				ItPl_simstep2 = m._PL_simstep2.tokens.begin();
				}
			}
			return false;
		break;
		case 7:	//generationInitiale

			if (not (ItVar_j == (((size_t) Color_Jeton_Total) - 1) )) { 
				ItVar_j++; return true;
			}
			ItVar_j = 0;
			return false;
		break;
		case 11:	//enter

			return false;
		break;
	}

return false;
	}
	bool isCoherent(size_t& t,abstractMarkingImpl& m) {
		 IsDefItVar_xs = false;
		 IsDefItVar_x = false;
		 IsDefItVar_ys = false;
		 IsDefItVar_y = false;
		 IsDefItVar_dxs = false;
		 IsDefItVar_dx = false;
		 IsDefItVar_dys = false;
		 IsDefItVar_dy = false;
		 IsDefItVar_ddx = false;
		 IsDefItVar_ddy = false;
		 IsDefItVar_j = false;	switch (t){
		case 2:	//simstepA

			if (m._PL_initGenere.tokens.empty()) { return false; }
			if (IsDefItVar_j) {
				if (not (ItVar_j == (*ItPl_initGenere).first.c0)) { return false; }
			}
			else {
				ItVar_j = (*ItPl_initGenere).first.c0;
				IsDefItVar_j = true;
				}
			return true;
		break;
		case 8:	//exit

			if (m._PL_otherVehicles.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_otherVehicles).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_otherVehicles).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_otherVehicles).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_otherVehicles).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dx) {
				if (not (ItVar_dx == (*ItPl_otherVehicles).first.c2)) { return false; }
			}
			else {
				ItVar_dx = (*ItPl_otherVehicles).first.c2;
				IsDefItVar_dx = true;
				}
			if (IsDefItVar_dy) {
				if (not (ItVar_dy == (*ItPl_otherVehicles).first.c3)) { return false; }
			}
			else {
				ItVar_dy = (*ItPl_otherVehicles).first.c3;
				IsDefItVar_dy = true;
				}
			if (m._PL_PositionMax.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_PositionMax).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_PositionMax).first.c0;
				IsDefItVar_x = true;
				}
			return true;
		break;
		case 9:	//end

			if (m._PL_selfVehicle.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_selfVehicle).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_selfVehicle).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_selfVehicle).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_selfVehicle).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dx) {
				if (not (ItVar_dx == (*ItPl_selfVehicle).first.c2)) { return false; }
			}
			else {
				ItVar_dx = (*ItPl_selfVehicle).first.c2;
				IsDefItVar_dx = true;
				}
			if (IsDefItVar_dy) {
				if (not (ItVar_dy == (*ItPl_selfVehicle).first.c3)) { return false; }
			}
			else {
				ItVar_dy = (*ItPl_selfVehicle).first.c3;
				IsDefItVar_dy = true;
				}
			if (IsDefItVar_ddx) {
				if (not (ItVar_ddx == (*ItPl_selfVehicle).first.c4)) { return false; }
			}
			else {
				ItVar_ddx = (*ItPl_selfVehicle).first.c4;
				IsDefItVar_ddx = true;
				}
			if (IsDefItVar_ddy) {
				if (not (ItVar_ddy == (*ItPl_selfVehicle).first.c5)) { return false; }
			}
			else {
				ItVar_ddy = (*ItPl_selfVehicle).first.c5;
				IsDefItVar_ddy = true;
				}
			if (m._PL_PositionMax.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_PositionMax).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_PositionMax).first.c0;
				IsDefItVar_x = true;
				}
			return true;
		break;
		case 0:	//updateSelf

			if (m._PL_selfVehicle.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_selfVehicle).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_selfVehicle).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_selfVehicle).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_selfVehicle).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dx) {
				if (not (ItVar_dx == (*ItPl_selfVehicle).first.c2)) { return false; }
			}
			else {
				ItVar_dx = (*ItPl_selfVehicle).first.c2;
				IsDefItVar_dx = true;
				}
			if (IsDefItVar_dy) {
				if (not (ItVar_dy == (*ItPl_selfVehicle).first.c3)) { return false; }
			}
			else {
				ItVar_dy = (*ItPl_selfVehicle).first.c3;
				IsDefItVar_dy = true;
				}
			if (IsDefItVar_ddx) {
				if (not (ItVar_ddx == (*ItPl_selfVehicle).first.c4)) { return false; }
			}
			else {
				ItVar_ddx = (*ItPl_selfVehicle).first.c4;
				IsDefItVar_ddx = true;
				}
			if (IsDefItVar_ddy) {
				if (not (ItVar_ddy == (*ItPl_selfVehicle).first.c5)) { return false; }
			}
			else {
				ItVar_ddy = (*ItPl_selfVehicle).first.c5;
				IsDefItVar_ddy = true;
				}
			if (m._PL_simstep3.tokens.empty()) { return false; }
			if (IsDefItVar_j) {
				if (not (ItVar_j == (*ItPl_simstep3).first.c0)) { return false; }
			}
			else {
				ItVar_j = (*ItPl_simstep3).first.c0;
				IsDefItVar_j = true;
				}
			return true;
		break;
		case 1:	//lightController

			if (m._PL_selfVehicle.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_selfVehicle).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_selfVehicle).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_selfVehicle).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_selfVehicle).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dx) {
				if (not (ItVar_dx == (*ItPl_selfVehicle).first.c2)) { return false; }
			}
			else {
				ItVar_dx = (*ItPl_selfVehicle).first.c2;
				IsDefItVar_dx = true;
				}
			if (IsDefItVar_dy) {
				if (not (ItVar_dy == (*ItPl_selfVehicle).first.c3)) { return false; }
			}
			else {
				ItVar_dy = (*ItPl_selfVehicle).first.c3;
				IsDefItVar_dy = true;
				}
			if (IsDefItVar_ddx) {
				if (not (ItVar_ddx == (*ItPl_selfVehicle).first.c4)) { return false; }
			}
			else {
				ItVar_ddx = (*ItPl_selfVehicle).first.c4;
				IsDefItVar_ddx = true;
				}
			if (IsDefItVar_ddy) {
				if (not (ItVar_ddy == (*ItPl_selfVehicle).first.c5)) { return false; }
			}
			else {
				ItVar_ddy = (*ItPl_selfVehicle).first.c5;
				IsDefItVar_ddy = true;
				}
			if (m._PL_simstep4.tokens.empty()) { return false; }
			if (IsDefItVar_j) {
				if (not (ItVar_j == (*ItPl_simstep4).first.c0)) { return false; }
			}
			else {
				ItVar_j = (*ItPl_simstep4).first.c0;
				IsDefItVar_j = true;
				}
			return true;
		break;
		case 10:	//collision

			if (m._PL_selfVehicle.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_selfVehicle).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_selfVehicle).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_selfVehicle).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_selfVehicle).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dxs) {
				if (not (ItVar_dxs == (*ItPl_selfVehicle).first.c2)) { return false; }
			}
			else {
				ItVar_dxs = (*ItPl_selfVehicle).first.c2;
				IsDefItVar_dxs = true;
				}
			if (IsDefItVar_dys) {
				if (not (ItVar_dys == (*ItPl_selfVehicle).first.c3)) { return false; }
			}
			else {
				ItVar_dys = (*ItPl_selfVehicle).first.c3;
				IsDefItVar_dys = true;
				}
			if (IsDefItVar_ddx) {
				if (not (ItVar_ddx == (*ItPl_selfVehicle).first.c4)) { return false; }
			}
			else {
				ItVar_ddx = (*ItPl_selfVehicle).first.c4;
				IsDefItVar_ddx = true;
				}
			if (IsDefItVar_ddy) {
				if (not (ItVar_ddy == (*ItPl_selfVehicle).first.c5)) { return false; }
			}
			else {
				ItVar_ddy = (*ItPl_selfVehicle).first.c5;
				IsDefItVar_ddy = true;
				}
			if (m._PL_otherVehicles.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_otherVehicles).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_otherVehicles).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_otherVehicles).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_otherVehicles).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dx) {
				if (not (ItVar_dx == (*ItPl_otherVehicles).first.c2)) { return false; }
			}
			else {
				ItVar_dx = (*ItPl_otherVehicles).first.c2;
				IsDefItVar_dx = true;
				}
			if (IsDefItVar_dy) {
				if (not (ItVar_dy == (*ItPl_otherVehicles).first.c3)) { return false; }
			}
			else {
				ItVar_dy = (*ItPl_otherVehicles).first.c3;
				IsDefItVar_dy = true;
				}
			return true;
		break;
		case 5:	//randOther

			if (m._PL_simstep1.tokens.empty()) { return false; }
			if (IsDefItVar_j) {
				if (not (ItVar_j == (*ItPl_simstep1).first.c0)) { return false; }
			}
			else {
				ItVar_j = (*ItPl_simstep1).first.c0;
				IsDefItVar_j = true;
				}
			if (m._PL_otherVehicles.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_otherVehicles).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_otherVehicles).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_otherVehicles).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_otherVehicles).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dx) {
				if (not (ItVar_dx == (*ItPl_otherVehicles).first.c2)) { return false; }
			}
			else {
				ItVar_dx = (*ItPl_otherVehicles).first.c2;
				IsDefItVar_dx = true;
				}
			if (IsDefItVar_dy) {
				if (not (ItVar_dy == (*ItPl_otherVehicles).first.c3)) { return false; }
			}
			else {
				ItVar_dy = (*ItPl_otherVehicles).first.c3;
				IsDefItVar_dy = true;
				}
			return true;
		break;
		case 3:	//simstepB

			if (m._PL_simstep1.tokens.empty()) { return false; }
			if (IsDefItVar_j) {
				if (not (ItVar_j == (*ItPl_simstep1).first.c0)) { return false; }
			}
			else {
				ItVar_j = (*ItPl_simstep1).first.c0;
				IsDefItVar_j = true;
				}
			return true;
		break;
		case 6:	//updOther

			if (m._PL_simstep2.tokens.empty()) { return false; }
			if (IsDefItVar_j) {
				if (not (ItVar_j == (*ItPl_simstep2).first.c0)) { return false; }
			}
			else {
				ItVar_j = (*ItPl_simstep2).first.c0;
				IsDefItVar_j = true;
				}
			if (m._PL_inProcess.tokens.empty()) { return false; }
			if (IsDefItVar_x) {
				if (not (ItVar_x == (*ItPl_inProcess).first.c0)) { return false; }
			}
			else {
				ItVar_x = (*ItPl_inProcess).first.c0;
				IsDefItVar_x = true;
				}
			if (IsDefItVar_y) {
				if (not (ItVar_y == (*ItPl_inProcess).first.c1)) { return false; }
			}
			else {
				ItVar_y = (*ItPl_inProcess).first.c1;
				IsDefItVar_y = true;
				}
			if (IsDefItVar_dx) {
				if (not (ItVar_dx == (*ItPl_inProcess).first.c2)) { return false; }
			}
			else {
				ItVar_dx = (*ItPl_inProcess).first.c2;
				IsDefItVar_dx = true;
				}
			if (IsDefItVar_dy) {
				if (not (ItVar_dy == (*ItPl_inProcess).first.c3)) { return false; }
			}
			else {
				ItVar_dy = (*ItPl_inProcess).first.c3;
				IsDefItVar_dy = true;
				}
			return true;
		break;
		case 4:	//simstepC

			if (m._PL_simstep2.tokens.empty()) { return false; }
			if (IsDefItVar_j) {
				if (not (ItVar_j == (*ItPl_simstep2).first.c0)) { return false; }
			}
			else {
				ItVar_j = (*ItPl_simstep2).first.c0;
				IsDefItVar_j = true;
				}
			return true;
		break;
		default:	//generationInitiale,enter,

			return true;
		break;
	}

		return true;
	}
public:

	bool next(size_t& t, abstractMarkingImpl& m);
	size_t getIndex();
	abstractBinding getBinding();};
#endif
