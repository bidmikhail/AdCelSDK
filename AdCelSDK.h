//
//  AdCelSDK.h
//
//  Copyright (c) 2015 AdCel. All rights reserved.
//
 
#import <Foundation/Foundation.h>

#define ADCELSDK_VERSION (@"1.6.0")

#define ADCEL_IMAGE_INTERSTITIAL (@"Image")
#define ADCEL_VIDEO_INTERSTITIAL (@"Video")
#define ADCEL_INTERSTITIAL (@"Interstitial")//Video or Image

#define ADCEL_REWARDED_INTERSTITIAL (@"Rewarded")
#define ADCEL_BANNER (@"Banner")

/** ADS PROVIDERS **/
#define ADCEL_PROVIDER_ADCOLONY_IDT       (1)
#define ADCEL_PROVIDER_SMAATO_IDT         (3)
#define ADCEL_PROVIDER_STARTAPP_IDT       (5)
#define ADCEL_PROVIDER_INMOBI_IDT         (6)
#define ADCEL_PROVIDER_GOOGLEADMOBS_IDT   (7)
#define ADCEL_PROVIDER_APPLOVIN_IDT       (8)
#define ADCEL_PROVIDER_TAPJOY_IDT         (15)
#define ADCEL_PROVIDER_AMAZON_IDT         (16)
#define ADCEL_PROVIDER_VUNGLE_IDT         (17)
#define ADCEL_PROVIDER_MYTARGET_IDT       (21)
#define ADCEL_PROVIDER_UNITY_IDT          (22)
#define ADCEL_PROVIDER_YANDEX_IDT         (26)
#define ADCEL_PROVIDER_SUPERSONIC_IDT     (27)
#define ADCEL_PROVIDER_INHOUSE_IDT        (30)
#define ADCEL_PROVIDER_FACEBOOK_IDT       (31)
#define ADCEL_PROVIDER_RTB_IDT            (40)
#define ADCEL_PROVIDER_PANGLE_IDT         (42)
#define ADCEL_PROVIDER_CRITEO_IDT         (43)
#define ADCEL_PROVIDER_APS_IDT            (45)
#define ADCEL_PROVIDER_OUTBRAIN_IDT       (46)
#define ADCEL_PROVIDER_FYBER_IDT          (47)
#define ADCEL_PROVIDER_GAM_IDT            (48)

#define ADCEL_PROVIDER_TEST_IDT           (32767)
/***/

@class UIViewController;

/**
 The methods declared by the AdCelSDKDelegate protocol allow the adopting delegate to respond to messages from fullscreen ads and thus respond to, and in some affect, operations such as appearance/disappearance of advertising on/from screen, clicking, receiving of reward, first load of an ad and failure to display ad.
 */
@protocol AdCelSDKDelegate <NSObject>

/**
 Called right before appearance of an ad on the screen.
 */
-(void)onAdWillAppear:(NSString*)adType providerId:(int)providerId;

/**
 Called immediately after disappearance of an ad from the screen.
 */
-(void)onAdDidDisappear:(NSString*)adType providerId:(int)providerId;

@optional

/**
 A view controller to use for presenting modal ad content
 If not implemented, SDK will try to find the top most view controller and show interstitial from there
 */
-(UIViewController*)viewControllerForPresentingModalView;

/**
 Called if the user has viewed an ad and receives a reward
 */
-(void)onReward:(int)reward currency:(NSString*)gameCurrency providerId:(int)providerId;

/**
 Tells the delegate when the user clicks on fullscreen ad.
 */
-(void)onAdClicked:(NSString*)adType providerId:(int)providerId;

/**
 Called right before appearance of fullscreen ad on the screen. Return YES if you want to display ad. Otherwise, return NO.
 */
-(BOOL)shouldShowAd:(NSString*)adType;

/**
 Tells the delegate that the AdCel SDK has failed to display fullscreen ad.
 */
-(void)onAdFailedToAppear:(NSString*)adType;

/**
 Tells the delegate that AdCel SDK has loaded the first fullscreen ad and it is ready to be shown.
 */
-(void)onFirstAdLoaded:(NSString*)adType;

@end

@interface AdCelSDK : NSObject

/**
 Initialization of the AdCel SDK on startup.
  @appId is taken from the instruction on the adcel.com website
  @modules is an array of constants that are used to show ads in your application. Each them must be one of following constants: ADCEL_IMAGE_INTERSTITIAL, ADCEL_VIDEO_INTERSTITIAL, ADCEL_INTERSTITIAL, ADCEL_REWARDED_INTERSTITIAL and ADCEL_BANNER. For performance reasons, it is strongly recommended to exclude constants that are not used to show ads. If you want to show small banners, include ADCEL_BANNER constant in this array.
 */
+(void)startWithAppId:(NSString*)appId modules:(NSArray*)modules;

/**
 Sets the delegate to respond to messages from fullscreen ads and thus respond to, and in some affect, operations such as appearance/disappearance of advertising on/from screen, clicking, receiving of reward, first load of an ad and failure to display ad.
 */
+(void)setDelegate:(id<AdCelSDKDelegate>)delegate;

/**
 A boolean value that determines whether there is an ad on the screen or not.
 */
+(BOOL)isInterstitialDisplayed;

/**
 Enables verbose console logs for debugging purpurses.
 */
+(void)enableDebugLogs;

/**
 Enables test mode.
 */
+(void)enableTestMode;

/**
 @brief Shows interstitial ads. Can only be called from the main thread.
 @param typeOfInterstitial Can be one of ADCEL_IMAGE_INTERSTITIAL, ADCEL_VIDEO_INTERSTITIAL, ADCEL_INTERSTITIAL, ADCEL_REWARDED_INTERSTITIAL.
 @warning It is strongly recommended to use ADCEL_INTERSTITIAL to show ads because this will maximize revenue.
 */
+(BOOL)showInterstitial:(NSString*)typeOfInterstitial;

/**
 @brief Shows interstitial ads. Can only be called from the main thread.
 @param typeOfInterstitial can be ADCEL_IMAGE_INTERSTITIAL, ADCEL_VIDEO_INTERSTITIAL, ADCEL_INTERSTITIAL or ADCEL_REWARDED_INTERSTITIAL. It is strongly recommended to use ADCEL_INTERSTITIAL to show ads because this will maximize revenue.
 @param vc is the active topmost view controller. Make sure it will not be removed from the screen when the user watch the ad.
 */
+(BOOL)showInterstitial:(NSString*)typeOfInterstitial fromViewController:(UIViewController*)vc __deprecated_msg("will be removed in a future SDK version. Use 'viewControllerForPresentingModalView' delegate call to specify 'viewController' for presenting interstitial ad");

/**
 Can only be called from the main thread. It is strongly recommended to avoid using this method. Because it makes our analytic logs too complex to be analyzed quickly. If you want to handle failure to display ads by showInterstitial: and showInterstitial:fromViewController: methods, please use onAdFailedToAppear: delegate method.
  @typeOfInterstitial can be ADCEL_IMAGE_INTERSTITIAL, ADCEL_VIDEO_INTERSTITIAL, ADCEL_INTERSTITIAL or ADCEL_REWARDED_INTERSTITIAL.
*/
+(BOOL)hasInterstitial:(NSString*)typeOfInterstitial;

/** Hides the displayed interstitial ad if it is supported by the current provider. Can only be called from the main thread.
 */
+(BOOL)hideInterstitial;

/** Currency and value which will be returned by the onReward:currency: delegate method.
 */
+(NSString*)rewardedCurrency;
+(int)rewardedValue;

/**
 * Provide with per-user non personally-identifiable information for ad targeting purposes.
 * Providing non personally-identifiable information using this API will improve targeting and unlock
 * improved earnings for your app.
 * @param targetingParam One of the predefined targeting keys.
 * @param value Either a predefined targeting value, or arbitrary value.
 */
+(void)setTargetingParam:(NSString*)targetingParam value:(NSString*)value;

/**
 * Use this to communicate an EEU Data Subject's preference regarding data collection.
 * Set whether or not user has provided consent for sharing data with AdCel and Ads providers.
 * Note: this method should be called before starting the AdCel SDK with startWithAppId:modules:
 * @param consent 'YES' if the user has provided consent for sharing data with AdCel and Ads providers. 'YES' by default.
 */
+(void)setUserConsent:(BOOL)consent;

/**
 * @brief Getter for the previous method (see above).
 */
+(BOOL)userConsent;

/**
 *  @brief Returns YES if the userConsent value (see above) is set by the setUserConsent method. Otherwise returns NO.
 */
+(BOOL)consentValueDidSet;

@end
