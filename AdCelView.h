//
//  AdCelView.h
//
//  Copyright (c) 2015 AdCel. All rights reserved.
//

#import <UIKit/UIKit.h>

#define ADCELSDK_BANNER_SIZE_300x50  (@"300x50")
#define ADCELSDK_BANNER_SIZE_320x50  (@"320x50")
#define ADCELSDK_BANNER_SIZE_728x90  (@"728x90")
#define ADCELSDK_BANNER_SIZE_768x90  (@"768x90")
#define ADCELSDK_BANNER_SIZE_300x250 (@"300x250")

#define ADCELSDK_BANNER_POSITION_TOP_LEFT (@"0;0")
#define ADCELSDK_BANNER_POSITION_TOP_CENTER (@"1;0")
#define ADCELSDK_BANNER_POSITION_TOP_RIGHT (@"2;0")
#define ADCELSDK_BANNER_POSITION_CENTER_LEFT (@"0;1")
#define ADCELSDK_BANNER_POSITION_CENTER (@"1;1")
#define ADCELSDK_BANNER_POSITION_CENTER_RIGHT (@"2;1")
#define ADCELSDK_BANNER_POSITION_BOTTOM_LEFT (@"0;2")
#define ADCELSDK_BANNER_POSITION_BOTTOM (@"1;2")
#define ADCELSDK_BANNER_POSITION_BOTTOM_RIGHT (@"2;2")

#import "AdCelBaseView.h"

@class AdCelView;

/**
 The methods declared by the AdCelViewDelegate protocol allow the adopting delegate to respond to messages from AdCelView and thus respond to operations such as displaying of ad, failure to display ad and clicking on ad.
 */
@protocol AdCelViewDelegate <NSObject>

@optional

/**
 Called if AdCel view has successfully displayed an ad.
 */
-(void)adCelViewDidDisplayAd:(AdCelView*)adCelView providerId:(int)providerId;

/**
 Called if ad provider has failed to display an ad.
 */
-(void)adCelView:(AdCelView*)adCelView failedToDisplayAdWithError:(NSError*)error isConnectionError:(BOOL)isConnectionError;

/**
 Called if all of the ad providers in the queue have failed to display ad.
 */
-(void)allProvidersFailedToDisplayAdInView:(AdCelView*)adCelView;

/**
 Called when the user clicks on the displayed ad.
 */
-(void)adCelViewOnClick:(AdCelView*)view providerId:(int)providerId;

@end

@interface AdCelView : AdCelBaseView

/**
 Sets the delegate to respond to messages from AdCelView and thus respond to operations such as displaying of ad, failure to display ad and clicking on ad.
 */
@property (nonatomic, weak) id<AdCelViewDelegate> delegate;

/**
 A boolean value that determines whether there is an ad displayed on the AdCelView.
 */
@property (nonatomic, readonly) BOOL adIsDisplayed;

/**
 Identifier string for the zone this banner should load ads for;
*/
@property(nonatomic, retain) NSString* zone;

/**
 Banner refresh interval in seconds. Default is 30. The zero value indicates that automatic refreshing is disabled and you should refresh ads manually by calling loadNextAd method.
*/
-(NSTimeInterval)refreshInterval;

/**
 Sets banner refresh interval.
 @refreshInterval banner refresh interval in seconds. Default is 30. The zero value can be set to disable automatic refreshing and to refresh ads manually by calling loadNextAd method.
 */
-(void)setRefreshInterval:(NSTimeInterval)refreshInterval;

/**
 Refreshes banner manually.
 */
-(void)loadNextAd;

/**
 Init the AdCelView instance.
 @bannerSize can be one of predefined values:
    ADCELSDK_BANNER_SIZE_300x50
    ADCELSDK_BANNER_SIZE_320x50
    ADCELSDK_BANNER_SIZE_728x90
    ADCELSDK_BANNER_SIZE_768x90
    ADCELSDK_BANNER_SIZE_300x250
 It is strongly recommended to use only ADCELSDK_BANNER_SIZE_320x50 or ADCELSDK_BANNER_SIZE_768x90 to archive the maximum revenue.
 @delegate to respond to messages from AdCelView and thus respond to operations such as displaying of ad, failure to display ad and clicking on ad.
 */
-(id)initWithBannerSize:(NSString*)bannerSize delegate:(id<AdCelViewDelegate>)delegate;

/**
 Init the AdCelView instance.
 @view the parent view on which your banner ad will be displayed.
 @position inside the parent @view. Can be one of the following:
    ADCELSDK_BANNER_POSITION_TOP_LEFT
    ADCELSDK_BANNER_POSITION_TOP_CENTER
    ADCELSDK_BANNER_POSITION_TOP_RIGHT
    ADCELSDK_BANNER_POSITION_CENTER_LEFT
    ADCELSDK_BANNER_POSITION_CENTER
    ADCELSDK_BANNER_POSITION_CENTER_RIGHT
    ADCELSDK_BANNER_POSITION_BOTTOM_LEFT
    ADCELSDK_BANNER_POSITION_BOTTOM
    ADCELSDK_BANNER_POSITION_BOTTOM_RIGHT
 @edgeInsets to specify additional edge insets of your banner.
 @bannerSize can be one of predefined values:
    ADCELSDK_BANNER_SIZE_300x50
    ADCELSDK_BANNER_SIZE_320x50
    ADCELSDK_BANNER_SIZE_728x90
    ADCELSDK_BANNER_SIZE_768x90
    ADCELSDK_BANNER_SIZE_300x250
 It is strongly recommended to use only ADCELSDK_BANNER_SIZE_320x50 or ADCELSDK_BANNER_SIZE_768x90 to archive the maximum revenue.
 @delegate to respond to messages from AdCelView and thus respond to operations such as displaying of ad, failure to display ad and clicking on ad.
 */
+(id)attachToView:(UIView*)view position:(NSString*)position edgeInsets:(UIEdgeInsets)edgeInsets bannerSize:(NSString*)bannerSize delegate:(id<AdCelViewDelegate>)delegate;

@end


