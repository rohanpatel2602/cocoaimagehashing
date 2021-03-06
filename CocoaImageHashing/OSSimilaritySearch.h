//
//  OSSimilaritySearch.h
//  CocoaImageHashing
//
//  Created by Andreas Meingast on 16/10/15.
//  Copyright © 2015 Andreas Meingast. All rights reserved.
//

#import "OSTypes.h"

@interface OSSimilaritySearch : NSObject

NS_ASSUME_NONNULL_BEGIN

+ (instancetype)sharedInstance;

#pragma mark - Array & Stream Based Similarity Search

- (void)similarImagesWithProvider:(OSImageHashingProviderId)imageHashingProviderId
        withHashDistanceThreshold:(OSHashDistanceType)hashDistanceThreshold
            forImageStreamHandler:(OSTuple<OSImageId *, NSData *> * (^)())imageStreamHandler
                 forResultHandler:(void (^)(OSImageId *leftHandImageId, OSImageId *rightHandImageId))resultHandler;

- (NSArray<OSTuple<OSImageId *, OSImageId *> *> *)similarImagesWithProvider:(OSImageHashingProviderId)imageHashingProviderId
                                                  withHashDistanceThreshold:(OSHashDistanceType)hashDistanceThreshold
                                                      forImageStreamHandler:(OSTuple<OSImageId *, NSData *> * (^)())imageStreamHandler;

- (NSArray<OSTuple<OSImageId *, OSImageId *> *> *)similarImagesWithProvider:(OSImageHashingProviderId)imageHashingProviderId
                                                  withHashDistanceThreshold:(OSHashDistanceType)hashDistanceThreshold
                                                                  forImages:(NSArray<OSTuple<OSImageId *, NSData *> *> *)imageTuples;

#pragma mark - Result Conversion

- (NSDictionary<OSImageId *, NSSet<OSImageId *> *> *)dictionaryFromSimilarImagesResult:(NSArray<OSTuple<OSImageId *, OSImageId *> *> *)similarImageTuples;

NS_ASSUME_NONNULL_END

@end
