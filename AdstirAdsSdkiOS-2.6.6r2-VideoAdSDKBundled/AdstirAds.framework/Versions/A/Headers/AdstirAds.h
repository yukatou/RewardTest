//
//  AdstirAds.h
//  AdstirAds
//
//  Copyright © 2015 UNITED, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
#error Adstir Ads SDK requires a deployment target of iOS 6.0 or later.
#endif

//! Project version string for AdstirAds.
FOUNDATION_EXPORT const unsigned char AdstirAdsVersionString[];

#import <AdstirAds/AdstirConfig.h>
#import <AdstirAds/AdstirAdSize.h>

#import <AdstirAds/AdstirMraidView.h>
#import <AdstirAds/AdstirNativeAd.h>
#import <AdstirAds/AdstirVideoReward.h>