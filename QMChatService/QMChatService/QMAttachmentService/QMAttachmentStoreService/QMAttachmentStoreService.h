//
//  QMMediaStoreService.h
//  QMMediaKit
//
//  Created by Vitaliy Gurkovsky on 2/7/17.
//  Copyright © 2017 quickblox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QMAttachmentStoreServiceDelegate.h"
#import "QMAttachmentsMemoryStorage.h"
#import "QMCancellableService.h"

/**
 The options for the cache types for attachment. Uses for saving to cache.
 */
typedef NS_OPTIONS(NSInteger, QMAttachmentCacheType) {
    /**
     * Memory cache. QMAttachmentStoreService should save the attachment to the memory cache.
     */
    QMAttachmentCacheTypeMemory =  0,
    
    /**
     * Disck cache. QMAttachmentStoreService should save the attachment to the disck cache.
     */
    QMAttachmentCacheTypeDisc = 1 << 0
};

NS_ASSUME_NONNULL_BEGIN

@interface QMAttachmentStoreService : NSObject <QMCancellableService>

/**
 Memory storage for attachments.
 */
@property (strong, nonatomic, readonly) QMAttachmentsMemoryStorage *attachmentsMemoryStorage;

/**
 Attachment store service delegate
 */
@property (nonatomic, weak, nullable) id <QMAttachmentStoreServiceDelegate> storeDelegate;

/**
 Initializes an `QMAttachmentStoreService` object with the specified '<QMAttachmentStoreServiceDelegate>'.
 
 @param delegate The instance that confirms @<QMAttachmentStoreServiceDelegate>.
 @return The newly-initialized 'QMAttachmentStoreService'.
 */
- (instancetype)initWithDelegate:(id <QMAttachmentStoreServiceDelegate>)delegate;

/**
 Updates saved 'QBChatAttachment' instance in cache.
 
 @param attachment 'QBChatAttachment' instance.
 @param messageID The message ID that contains attachment.
 @param dialogID The dialog ID.
 */
- (void)updateAttachment:(QBChatAttachment *)attachment
               messageID:(NSString *)messageID
                dialogID:(NSString *)dialogID;

/**
 Gets cached image from attachment.
 
 @param attachment 'QBChatAttachment' instance.
 @param messageID The message ID that contains attachment.
 @param dialogID  The dialog ID.
 @param completion The block with the cached image.
 */
- (void)cachedImageForAttachment:(QBChatAttachment *)attachment
                       messageID:(NSString *)messageID
                        dialogID:(NSString *)dialogID
                      completion:(void(^)(UIImage * _Nullable image))completion;

/**
 Gets `NSData` representation for provided image.
 
 @param image 'UIImage' instance.
 @return `NSData` instance.
 */
- (NSData *)dataForImage:(UIImage *)image;

/**
 Gets cached data and file URL for attachment.
 
 @param attachment 'QBChatAttachment' instance.
 @param messageID The message ID that contains attachment.
 @param dialogID The dialog ID.
 @param completion  If the attachment was founded in the cache, the block will be with fileURL and data parameters set.
 *
 */
- (void)cachedDataForAttachment:(QBChatAttachment *)attachment
                      messageID:(NSString *)messageID
                       dialogID:(NSString *)dialogID
                     completion:(void(^)(NSURL *_Nullable fileURL, NSData *_Nullable data))completion;

/**
 Save and cache data for attachment for provided cache type.
 
 @param data 'NSData' instance.
 @param attachment 'QBChatAttachment' instance.
 @param cacheType Type of the cache.
 @param messageID The message ID that contains attachment.
 @param dialogID The dialog ID.
 @param completion The block to be invoked when finishes the saving.
 */
- (void)saveData:(NSData *)data
   forAttachment:(QBChatAttachment *)attachment
       cacheType:(QMAttachmentCacheType)cacheType
       messageID:(NSString *)messageID
        dialogID:(NSString *)dialogID
      completion:(nullable dispatch_block_t)completion;

/**
 Save and cache attachment for provided cache type.
 
 @param attachment 'QBChatAttachment' instance.
 @param cacheType Type of the cache.
 @param messageID The message ID that contains attachment.
 @param dialogID The dialog ID.
 @param completion The block to be invoked when finishes the saving.
 */
- (void)saveAttachment:(QBChatAttachment *)attachment
             cacheType:(QMAttachmentCacheType)cacheType
             messageID:(NSString *)messageID
              dialogID:(NSString *)dialogID
            completion:(nullable dispatch_block_t)completion;


/**
 Gets file URL for saved attachment.
 
 @param attachment The 'QBChatAttachment' instance.
 @param messageID The message ID that contains attachment.
 @param dialogID The dialog ID.
 @return 'NSURL' instance.
 */
- (nullable NSURL *)fileURLForAttachment:(QBChatAttachment *)attachment
                               messageID:(NSString *)messageID
                                dialogID:(NSString *)dialogID;

/**
 Gets the 'QBChatAttachment'
 
 @param attachmentID The attachment ID.
 @param messageID The message ID that contains attachment.
 @return 'QBChatAttachment' instance if exists.
 */
- (nullable QBChatAttachment *)cachedAttachmentWithID:(NSString *)attachmentID
                                         forMessageID:(NSString *)messageID;

/**
 Gets size for provided dialog ID and message ID.
 
 @param dialogID dialogID The dialog ID.
 @param messageID The message ID that contains attachment.
 @param completionBlock The block with size.
 */



/**
 Gets size for provided dialog ID and message ID.
 
 @param messageID The message ID that contains attachment.
 @param dialogID  The dialog ID.
 
 @return Size in
 */
- (NSUInteger)sizeForMessageWithID:(nullable NSString *)messageID
                          dialogID:(NSString *)dialogID;


/**
 Clears all data related to attachments for specified dialogID and messages ID's array from provided cache type.
 
 @param cacheType Type of the cache.
 @param completion The block to be invoked when finishes the cleaning.
 */
- (void)clearCacheForType:(QMAttachmentCacheType)cacheType
               completion:(nullable dispatch_block_t)completion;

/**
 Clears all data related to attachments for specified dialogID from provided cache type.
 
 @param dialogID The dialog ID.
 @param cacheType Type of the cache.
 @param completion The block to be invoked when finishes the cleaning.
 */
- (void)clearCacheForDialogWithID:(NSString *)dialogID
                        cacheType:(QMAttachmentCacheType)cacheType
                       completion:(nullable dispatch_block_t)completion;

/**
 Clears all data related to attachments for specified dialogID and message ID from provided cache type.
 
 @param messageID The message ID that contains attachment.
 @param dialogID The dialog ID.
 @param cacheType Type of the cache.
 @param completion The block to be invoked when finishes the cleaning.
 */
- (void)clearCacheForMessageWithID:(NSString *)messageID
                          dialogID:(NSString *)dialogID
                         cacheType:(QMAttachmentCacheType)cacheType
                        completion:(nullable dispatch_block_t)completion;

/**
 Clears all data related to attachments for specified dialogID and messages ID's array from provided cache type.
 
 @param messagesIDs An instance of NSArray, containing messageIDs.
 @param dialogID The dialog ID.
 @param cacheType Type of the cache.
 @param completion The block to be invoked when finishes the cleaning.
 */
- (void)clearCacheForMessagesWithIDs:(NSArray <NSString *> *)messagesIDs
                            dialogID:(NSString *)dialogID
                           cacheType:(QMAttachmentCacheType)cacheType
                          completion:(nullable dispatch_block_t)completion;
@end

NS_ASSUME_NONNULL_END
