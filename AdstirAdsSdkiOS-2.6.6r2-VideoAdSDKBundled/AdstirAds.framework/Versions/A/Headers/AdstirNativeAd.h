//
//  AdstirNativeAd.h
//  AdstirAds
//
//  Copyright (c) 2014- UNITED, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AdstirNativeAd;

/**
 Delegate for Small Image Loader.
 
 Small Imageをロードする際に使用します。
 */
@protocol AdstirLoadSmallImageDeledate <NSObject>
/**
 Performed when Small Image loaded.
 
 Small Imageが読み込まれた際に呼ばれます。
 */
- (void)adstirDidLoadSmallImage:(NSData * __nonnull) data;
/**
 Performed when failed to load Small Image.
 
 Small Imageが読み込みに失敗した際に呼ばれます。
 */
- (void)adstirDidFailToLoadSmallImage;
@end


/**
 Delegate for Image Loader.
 
 Imageをロードする際に使用します。
 */
@protocol AdstirLoadImageDeledate <NSObject>
/**
 Performed when Image loaded.
 
 Imageが読み込まれた際に呼ばれます。
 */
- (void)adstirDidLoadImage:(NSData * __nonnull) data;
/**
 Performed when failed to load Image.
 
 Imageが読み込みに失敗した際に呼ばれます。
 */
- (void)adstirDidFailToLoadImage;
@end

@interface AdstirNativeAdResponse : NSObject

@property (nonatomic, weak) __nullable id<AdstirLoadSmallImageDeledate> loadSmallImageDelegate;
@property (nonatomic, weak) __nullable id<AdstirLoadImageDeledate> loadImageDelegate;

@property (nonatomic, readonly, copy, nullable) NSString* smallImageUrl;
@property (nonatomic, readonly, copy, nullable) NSString* imageUrl;
@property (nonatomic, readonly, copy, nullable) NSString* cta;
@property (nonatomic, readonly, copy, nullable) NSString* landingPageUrl;
@property (nonatomic, readonly, copy, nullable) NSString* title;
@property (nonatomic, readonly, copy, nullable) NSString* descriptionText;
@property (nonatomic, readonly, assign) float rating;
- (void)impression;
- (void)click;

+ (void)bindImageWithURL:(NSURL * __nonnull)url bindCallback:(void  (^ __nullable ) ( UIImage * __nonnull image))callback;

- (void)bindImageToImageView:(UIImageView * __nonnull)imageView;
- (void)bindSmallImageToImageView:(UIImageView * __nonnull)imageView;

- (void)bindImageToButton:(UIButton * __nonnull)button;
- (void)bindSmallImageToButton:(UIButton * __nonnull)button;

// Call by user to get the byte data of small image.
- (void)getSmallImageAsByte;
// Call by user to get the byte data of image.
- (void)getImageAsByte;

@end

@protocol AdstirNativeAdDelegate <NSObject>

/**
 Performed when receive ad.
 
 広告が取得できた際に呼び出されます。
 */
- (void)adstirNativeAdDidReceiveAd:(AdstirNativeAd * __nonnull)nativeAd response:(AdstirNativeAdResponse * __nonnull)response;
/**
 Performed when fail to receive ad.
 
 広告が取得できなかった際に呼び出されます。
 */
- (void)adstirNativeAdDidFailToReceiveAd:(AdstirNativeAd * __nonnull)nativeAd;

@end

@interface AdstirNativeAd : NSObject

@property (nonatomic, weak) __nullable id<AdstirNativeAdDelegate> delegate;
/**
 Set media ID.
 
 メディアIDを設定します。
 */
@property (nonatomic, copy, nonnull) NSString *media;
/**
 Set spot number.
 
 枠Noを設定します。
 */
@property (nonatomic, assign) NSUInteger spot;

/**
 広告であることを示すために掲載している文字列を入力します。
 */
@property (nonatomic, copy, nonnull) NSString *sponsoredText;

@property (nonatomic, assign) NSUInteger titleLength        __attribute__ ((deprecated));
@property (nonatomic, assign) NSUInteger descriptionLength  __attribute__ ((deprecated));
@property (nonatomic, assign) NSUInteger ctaLength          __attribute__ ((deprecated));
@property (nonatomic, assign) BOOL image                    __attribute__ ((deprecated));
@property (nonatomic, assign) BOOL smallImage               __attribute__ ((deprecated));
@property (nonatomic, assign) BOOL rating                   __attribute__ ((deprecated));
@property (nonatomic, assign) BOOL landingPageUrl           __attribute__ ((deprecated));

/**
 位置情報を広告配信に利用する場合に使用します。
 エンドユーザーへの許諾無しに、位置情報を利用することはできません。
 */
- (void)setLocationWithLatitude:(CGFloat)latitude
                      longitude:(CGFloat)longitude
                       accuracy:(CGFloat)accuracyInMeters;

- (void)getAd;

@end


