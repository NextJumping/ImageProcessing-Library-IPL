
//NOTE: NO HEADER GUARD ON PURPOSE! - This file is designed to be included multiple times

#include "PixelTemplateMacros.h"

#ifdef FUNCTION_IGNORE_Yb1
#define FUNCTION_IGNORE_PIXEL_TYPE_1
#endif

#ifdef FUNCTION_IGNORE_Yi1u
#define FUNCTION_IGNORE_PIXEL_TYPE_2
#endif

#ifdef FUNCTION_IGNORE_Yi4
#define FUNCTION_IGNORE_PIXEL_TYPE_3
#endif

#ifdef FUNCTION_IGNORE_RGBi1u
#define FUNCTION_IGNORE_PIXEL_TYPE_4
#endif

#ifdef FUNCTION_IGNORE_RGBi4
#define FUNCTION_IGNORE_PIXEL_TYPE_5
#endif

#ifdef FUNCTION_IGNORE_RGBf8
#define FUNCTION_IGNORE_PIXEL_TYPE_6
#endif

#ifdef FUNCTION_IGNORE_ARGBi1u
#define FUNCTION_IGNORE_PIXEL_TYPE_7
#endif

#ifdef FUNCTION_IGNORE_ARGBi4
#define FUNCTION_IGNORE_PIXEL_TYPE_8
#endif

#ifdef FUNCTION_IGNORE_YUVf8
#define FUNCTION_IGNORE_PIXEL_TYPE_9
#endif


#ifdef ONLY_F

#ifdef FUNCTION_TEMPLATE_RETURN

	#ifdef FUNCTION_TEMPLATE_ARGUMENT_2

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_1
		template FUNCTION_RETURN < PIXEL_TYPE_F_1 > FUNCTION_NAME < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_3 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_2
		template FUNCTION_RETURN < PIXEL_TYPE_F_2 > FUNCTION_NAME < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_3 ;
		#endif

	#elif defined(FUNCTION_TEMPLATE_ARGUMENT_1)

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_1
		template FUNCTION_RETURN < PIXEL_TYPE_F_1 > FUNCTION_NAME < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_2 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_2
		template FUNCTION_RETURN < PIXEL_TYPE_F_2 > FUNCTION_NAME < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_2 ;
		#endif

	#else

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_1
		template FUNCTION_RETURN < PIXEL_TYPE_F_1 > FUNCTION_NAME < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_2
		template FUNCTION_RETURN < PIXEL_TYPE_F_2 > FUNCTION_NAME < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE ;
		#endif

	#endif

#else

	#ifdef FUNCTION_TEMPLATE_ARGUMENT_2

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_1
		template FUNCTION_RETURN FUNCTION_NAME < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_3 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_2
		template FUNCTION_RETURN FUNCTION_NAME < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_3 ;
		#endif

	#elif defined(FUNCTION_TEMPLATE_ARGUMENT_1)

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_1
		template FUNCTION_RETURN FUNCTION_NAME < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE_2 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_2
		template FUNCTION_RETURN FUNCTION_NAME < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE_2 ;
		#endif

	#else

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_1
		template FUNCTION_RETURN FUNCTION_NAME < PIXEL_TYPE_F_1 > FUNCTION_SIGNATURE ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_2
		template FUNCTION_RETURN FUNCTION_NAME < PIXEL_TYPE_F_2 > FUNCTION_SIGNATURE ;
		#endif

	#endif


#endif

#else

#ifdef FUNCTION_TEMPLATE_RETURN

	#ifdef FUNCTION_TEMPLATE_ARGUMENT_2

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_1
		template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_3 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_2
		template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_3 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_3
		template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_3 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_4
		template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_3 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_5
		template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_3 ;
		#endif

		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_6
		template FUNCTION_RETURN < PIXEL_TYPE_6 > FUNCTION_NAME < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_3 ;
		#endif
		
		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_7
		template FUNCTION_RETURN < PIXEL_TYPE_7 > FUNCTION_NAME < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_3 ;
		#endif
		
		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_8
		template FUNCTION_RETURN < PIXEL_TYPE_8 > FUNCTION_NAME < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_3 ;
		#endif
		
		#ifndef FUNCTION_IGNORE_PIXEL_TYPE_9
		template FUNCTION_RETURN < PIXEL_TYPE_9 > FUNCTION_NAME < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_2 < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_3 ;
		#endif

	#elif defined(FUNCTION_TEMPLATE_ARGUMENT_1)

		#ifdef FUNCTION_DOUBLE_TEMPLATE

			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_3 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_4 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_5 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_6 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_7 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_8 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_1 > FUNCTION_NAME < PIXEL_TYPE_1 , PIXEL_TYPE_9 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_2 ;
			
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_3 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_4 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_5 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_6 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_7 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_8 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_2 > FUNCTION_NAME < PIXEL_TYPE_2 , PIXEL_TYPE_9 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_2 ;

			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_3 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_4 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_5 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_6 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_7 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_8 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_3 > FUNCTION_NAME < PIXEL_TYPE_3 , PIXEL_TYPE_9 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_2 ;

			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_3 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_4 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_5 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_6 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_7 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_8 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_4 > FUNCTION_NAME < PIXEL_TYPE_4 , PIXEL_TYPE_9 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_2 ;

			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_1 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_1 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_2 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_2 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_3 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_3 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_4 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_4 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_5 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_5 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_6 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_6 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_7 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_7 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_8 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_8 > FUNCTION_SIGNATURE_2 ;
			template FUNCTION_RETURN < PIXEL_TYPE_5 > FUNCTION_NAME < PIXEL_TYPE_5 , PIXEL_TYPE_9 > FUNCTION_SIGNATURE_1 < PIXEL_TYPE_9 > FUNCTION_SIGNATURE_2 ;

			