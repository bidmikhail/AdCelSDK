//
//  AdCelTargeting.h
//  AdCelSDK
//
//  Created 10/03/16.
//  Copyright © 2016 AdCel. All rights reserved.
//

#import <Foundation/Foundation.h>

#if defined(__cplusplus)
#define ADCEL_EXTERN extern "C"
#else
#define ADCEL_EXTERN extern
#endif

/**
 * @deprecated This method is deprecated starting from version 1.1.16
 * @note Use the following code instead: @code [AdCelSDK setTargetingParam: value:]
 */
ADCEL_EXTERN void AdCelSDK_setTargetingParam(NSString* targetingParam,NSString* value) __attribute__((deprecated("Use [AdCelSDK setTargetingParam: value:] instead")));

#pragma mark - Targeting Metadata Constants

/**
 * Targeting metadata keys
 */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_KEYWORDS;          /** application keywords. A free form set of keywords, separated by ',' e.g: @"sports,cars,bikes" */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_INTERESTS;    /** user's interests param. A free form set of interests, separated by ',' */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_AGE;          /** user's age param, e.g: @"25" */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_GENDER;       /** user's gender param */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_BIRTHDAY;     /** user's birthday param. Value should be in format dd.MM.yyyy, e.g: "01.01.2000" */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_OCCUPATION;   /** user's occupation param */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_RELATIONSHIP; /** user's relationship param */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_LATITUDE;     /** user's current latitude param */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_LONGITUDE;    /** user's current longitude param */

/**
 * Targeting metadata values (for pre-defined values)
 */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_GENDER_MALE;        /** User is male */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_GENDER_FEMALE;      /** User is female */

ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_OCCUPATION_SCHOOL;     /** User goes to school */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_OCCUPATION_UNIVERSITY; /** User at university */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_OCCUPATION_WORK;       /** User is working */

ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_RELATIONSHIP_SINGLE;   /** User is single */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_RELATIONSHIP_ENGAGED;  /** User is engaged */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_RELATIONSHIP_MARRIED;  /** User is married */
ADCEL_EXTERN NSString *const  ADCEL_TARGETING_PARAM_USER_RELATIONSHIP_DIVORCED; /** User is divorced */
