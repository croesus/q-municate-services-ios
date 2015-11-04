//
//  QMUsersService.h
//  QMUsersService
//
//  Created by Andrey Moskvin on 10/23/15.
//  Copyright © 2015 Quickblox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QMBaseService.h"
#import "QMUsersMemoryStorage.h"

@class QMCancellationToken;

@protocol QMUsersServiceDelegate;
@protocol QMUsersServiceCacheDataSource;

@interface QMUsersService : QMBaseService

/**
 *  Memory storage for users items.
 */
@property (strong, nonatomic, readonly) QMUsersMemoryStorage *usersMemoryStorage;

/**
 *  Init with service data delegate and users cache protocol.
 *
 *  @param serviceDataDelegate   instance confirmed id<QMServiceDataDelegate> protocol
 *  @param cacheDataSource       instance confirmed id<QMUsersServiceCacheDataSource> protocol
 *
 *  @return QMContactListService instance
 */
- (instancetype)initWithServiceManager:(id<QMServiceManagerProtocol>)serviceManager
                       cacheDataSource:(id<QMUsersServiceCacheDataSource>)cacheDataSource;

/**
 *  Add instance that confirms users service multicaste protocol.
 *
 *  @param delegate instance that confirms id<QMUsersServiceDelegate> protocol
 */
- (void)addDelegate:(id <QMUsersServiceDelegate>)delegate;

/**
 *  Remove instance that confirms users service multicaste protocol.
 *
 *  @param delegate instance that confirms id<QMUsersServiceDelegate> protocol
 */
- (void)removeDelegate:(id <QMUsersServiceDelegate>)delegate;

#pragma mark - Tasks

/**
 *  Load users to memory storage from disc cache.
 */
- (BFTask<NSArray<QBUUser *> *> *)loadFromCache;

#pragma mark - Intelligent fetch

/**
 *  Retrieve user with id.
 *
 *  @param userID   id of user to retreive
 *
 *  @return BFTask with QBUUser as a result
 */
- (BFTask<QBUUser *> *)retrieveUserWithID:(NSUInteger)userID;

/**
 *  Retrieve users with ids.
 *
 *  @param userIDs  array of user ids
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithIDs:(NSArray<NSNumber *> *)usersIDs;

/**
 *  Retrieve users by ids with extended pagination parameters.
 *
 *  @param userIDs  array of user ids
 *  @param page     QBGeneralResponsePage instance with extended pagination parameters
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithIDs:(NSArray<NSNumber *> *)usersIDs page:(QBGeneralResponsePage *)page;

/**
 *  Retrieve users with emails.
 *
 *  @param emails   array of user emails
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithEmails:(NSArray<NSString *> *)emails;

/**
 *  Retrieve users by emails with extended pagination parameters.
 *
 *  @param emails   array of user emails
 *  @param page     QBGeneralResponsePage instance with extended pagination parameters
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithEmails:(NSArray<NSString *> *)emails page:(QBGeneralResponsePage *)page;

/**
 *  Retrieve users with facebook ids.
 *
 *  @param facebookIDs  array of user facebook ids
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithFacebookIDs:(NSArray<NSString *> *)facebookIDs;

/**
 *  Retrieve users by facebook ids with extended pagination parameters.
 *
 *  @param facebookIDs  array of user facebook ids
 *  @param page         QBGeneralResponsePage instance with extended pagination parameters
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithFacebookIDs:(NSArray<NSString *> *)facebookIDs page:(QBGeneralResponsePage *)page;

/**
 *  Retrieve users with logins.
 *
 *  @param logins   array of user logins
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithLogins:(NSArray<NSString *> *)logins;

/**
 *  Retrieve users by logins with extended pagination parameters.
 *
 *  @param logins   array of user logins
 *  @param page     QBGeneralResponsePage instance with extended pagination parameters
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)retrieveUsersWithLogins:(NSArray<NSString *> *)logins page:(QBGeneralResponsePage *)page;


#pragma mark - Search

/**
 *  Search for users with full name.
 *
 *  @param searchText   user full name
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)searchUsersWithFullName:(NSString *)searchText;

/**
 *  Search for users by full name with extended pagination parameters.
 *
 *  @param searchText   user full name
 *  @param page         QBGeneralResponsePage instance with extended pagination parameters
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)searchUsersWithFullName:(NSString *)searchText page:(QBGeneralResponsePage *)page;

/**
 *  Search for users with tags.
 *
 *  @param tags   array of user tags
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)searchUsersWithTags:(NSArray<NSString *> *)tags;

/**
 *  Search for users by tags with extended pagination parameters.
 *
 *  @param tags   array of user tags
 *  @param page   QBGeneralResponsePage instance with extended pagination parameters
 *
 *  @return BFTask with NSArray of QBUUser instances as a result
 */
- (BFTask<NSArray<QBUUser *> *> *)searchUsersWithTags:(NSArray<NSString *> *)tags page:(QBGeneralResponsePage *)page;

@end

#pragma mark - Protocols

/**
 *  Data source for QMUsersService
 */

@protocol QMUsersServiceCacheDataSource <NSObject>
@required

/**
 *  Is called when users service will start. Need to use for inserting initial data QMUsersMemoryStorage.
 *
 *  @param block Block for provide QBUUsers collection
 */
- (void)cachedUsers:(void(^)(NSArray* collection))block;

@end

@protocol QMUsersServiceDelegate <NSObject>

@optional

/**
 *  Is called when users were added to QMUsersService.
 *
 *  @param usersService     QMUsersService instance
 *  @param user             NSArray of QBUUser instances as users
 */
- (void)usersService:(QMUsersService *)usersService didAddUsers:(NSArray<QBUUser *> *)user;

@end
