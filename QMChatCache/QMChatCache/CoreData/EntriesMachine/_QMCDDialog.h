// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to QMCDDialog.h instead.

#if __has_feature(modules)
    @import Foundation;
    @import CoreData;
#else
    #import <Foundation/Foundation.h>
    #import <CoreData/CoreData.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class QMCDMessage;

@class NSObject;

@class NSObject;

@interface QMCDDialogID : NSManagedObjectID {}
@end

@interface _QMCDDialog : NSManagedObject
+ (instancetype)insertInManagedObjectContext:(NSManagedObjectContext *)moc_;
+ (NSString*)entityName;
+ (nullable NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
@property (nonatomic, readonly, strong) QMCDDialogID *objectID;

@property (nonatomic, strong, nullable) NSDate* createdAt;

@property (nonatomic, strong, nullable) id data;

@property (nonatomic, strong, nullable) NSString* dialogID;

@property (nonatomic, strong, nullable) NSNumber* dialogType;

@property (atomic) int16_t dialogTypeValue;
- (int16_t)dialogTypeValue;
- (void)setDialogTypeValue:(int16_t)value_;

@property (nonatomic, strong, nullable) NSDate* lastMessageDate;

@property (nonatomic, strong, nullable) NSString* lastMessageText;

@property (nonatomic, strong, nullable) NSNumber* lastMessageUserID;

@property (atomic) int32_t lastMessageUserIDValue;
- (int32_t)lastMessageUserIDValue;
- (void)setLastMessageUserIDValue:(int32_t)value_;

@property (nonatomic, strong, nullable) NSString* name;

@property (nonatomic, strong, nullable) id occupantsIDs;

@property (nonatomic, strong, nullable) NSString* photo;

@property (nonatomic, strong, nullable) NSNumber* recipientID;

@property (atomic) int32_t recipientIDValue;
- (int32_t)recipientIDValue;
- (void)setRecipientIDValue:(int32_t)value_;

@property (nonatomic, strong, nullable) NSNumber* unreadMessagesCount;

@property (atomic) int32_t unreadMessagesCountValue;
- (int32_t)unreadMessagesCountValue;
- (void)setUnreadMessagesCountValue:(int32_t)value_;

@property (nonatomic, strong, nullable) NSDate* updatedAt;

@property (nonatomic, strong, nullable) NSNumber* userID;

@property (atomic) int32_t userIDValue;
- (int32_t)userIDValue;
- (void)setUserIDValue:(int32_t)value_;

@property (nonatomic, strong, nullable) NSSet<QMCDMessage*> *messages;
- (nullable NSMutableSet<QMCDMessage*>*)messagesSet;

@end

@interface _QMCDDialog (MessagesCoreDataGeneratedAccessors)
- (void)addMessages:(NSSet<QMCDMessage*>*)value_;
- (void)removeMessages:(NSSet<QMCDMessage*>*)value_;
- (void)addMessagesObject:(QMCDMessage*)value_;
- (void)removeMessagesObject:(QMCDMessage*)value_;

@end

@interface _QMCDDialog (CoreDataGeneratedPrimitiveAccessors)

- (nullable NSDate*)primitiveCreatedAt;
- (void)setPrimitiveCreatedAt:(nullable NSDate*)value;

- (nullable id)primitiveData;
- (void)setPrimitiveData:(nullable id)value;

- (nullable NSString*)primitiveDialogID;
- (void)setPrimitiveDialogID:(nullable NSString*)value;

- (nullable NSNumber*)primitiveDialogType;
- (void)setPrimitiveDialogType:(nullable NSNumber*)value;

- (int16_t)primitiveDialogTypeValue;
- (void)setPrimitiveDialogTypeValue:(int16_t)value_;

- (nullable NSDate*)primitiveLastMessageDate;
- (void)setPrimitiveLastMessageDate:(nullable NSDate*)value;

- (nullable NSString*)primitiveLastMessageText;
- (void)setPrimitiveLastMessageText:(nullable NSString*)value;

- (nullable NSNumber*)primitiveLastMessageUserID;
- (void)setPrimitiveLastMessageUserID:(nullable NSNumber*)value;

- (int32_t)primitiveLastMessageUserIDValue;
- (void)setPrimitiveLastMessageUserIDValue:(int32_t)value_;

- (nullable NSString*)primitiveName;
- (void)setPrimitiveName:(nullable NSString*)value;

- (nullable id)primitiveOccupantsIDs;
- (void)setPrimitiveOccupantsIDs:(nullable id)value;

- (nullable NSString*)primitivePhoto;
- (void)setPrimitivePhoto:(nullable NSString*)value;

- (nullable NSNumber*)primitiveRecipientID;
- (void)setPrimitiveRecipientID:(nullable NSNumber*)value;

- (int32_t)primitiveRecipientIDValue;
- (void)setPrimitiveRecipientIDValue:(int32_t)value_;

- (nullable NSNumber*)primitiveUnreadMessagesCount;
- (void)setPrimitiveUnreadMessagesCount:(nullable NSNumber*)value;

- (int32_t)primitiveUnreadMessagesCountValue;
- (void)setPrimitiveUnreadMessagesCountValue:(int32_t)value_;

- (nullable NSDate*)primitiveUpdatedAt;
- (void)setPrimitiveUpdatedAt:(nullable NSDate*)value;

- (nullable NSNumber*)primitiveUserID;
- (void)setPrimitiveUserID:(nullable NSNumber*)value;

- (int32_t)primitiveUserIDValue;
- (void)setPrimitiveUserIDValue:(int32_t)value_;

- (NSMutableSet<QMCDMessage*>*)primitiveMessages;
- (void)setPrimitiveMessages:(NSMutableSet<QMCDMessage*>*)value;

@end

@interface QMCDDialogAttributes: NSObject 
+ (NSString *)createdAt;
+ (NSString *)data;
+ (NSString *)dialogID;
+ (NSString *)dialogType;
+ (NSString *)lastMessageDate;
+ (NSString *)lastMessageText;
+ (NSString *)lastMessageUserID;
+ (NSString *)name;
+ (NSString *)occupantsIDs;
+ (NSString *)photo;
+ (NSString *)recipientID;
+ (NSString *)unreadMessagesCount;
+ (NSString *)updatedAt;
+ (NSString *)userID;
@end

@interface QMCDDialogRelationships: NSObject
+ (NSString *)messages;
@end

NS_ASSUME_NONNULL_END
