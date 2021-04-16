//
// TuyaSmartTimer.h
// TuyaSmartTimerKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartTimer
#define TuyaSmart_TuyaSmartTimer

#import <TuyaSmartUtil/TuyaSmartUtil.h>

/// Timer detail model.
@interface TYTimerModel : NSObject

/// The id of timer.
@property (nonatomic, strong) NSString *timerId;

/// Date.
@property (nonatomic, strong) NSString *date;

/// The timer execute time.
@property (nonatomic, strong) NSString *time;

/// The timer status.
@property (nonatomic, assign) BOOL     status;

/// The timer loop.
@property (nonatomic, strong) NSString *loops;

/// The timer action dps.
@property (nonatomic, strong) NSDictionary *dps;

/// The timer zone id.
@property (nonatomic, strong) NSString *timezoneId;

/// The timer alias name.
@property (nonatomic, copy)   NSString *aliasName;

/// Timer push notify, if yes, when timer execute, app will receive a notify message.
@property (nonatomic, assign) BOOL     isAppPush;

@end

/// Timer task model.
@interface TYTimerTaskModel : NSObject

/// The task name.
@property (nonatomic, strong) NSString  *taskName;

// The task status.
@property (nonatomic, assign) NSInteger status;

@end


/// @brief TuyaSmartTimer provides basic timing capability, supporting device timing (including WiFi devices, Bluetooth Mesh sub-devices, Zigbee sub-devices) and group timing.
///
/// It also encapsulates the interface of adding, deleting and checking timer information for device dp points. After the application sets up the timer information through the timing interface, the hardware module will automatically perform the booked operations according to the timing requirements. Multiple timers can be included under each timing task.
@interface TuyaSmartTimer : NSObject

/// Get a list of timer task.
/// @param devId Provides the device ID which is needed to get the timer task.
/// @param success Called when the task finishes successfully. A list of TYTimerTaskModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTimerTaskStatusWithDeviceId:(NSString *)devId
                               success:(void(^)(NSArray<TYTimerTaskModel *> *list))success
                               failure:(TYFailureError)failure;


/// Call this method to get all timers that the specified device has.
/// @param devId Provides the device ID which is needed to get all timers.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getAllTimerWithDeviceId:(NSString *)devId
                        success:(TYSuccessDict)success
                        failure:(TYFailureError)failure;


/// Call this method to update the timezone of a specified device.
/// @param devId Provides the device ID which is needed to update the timezone.
/// @param timezoneId The ID of the time zone, for example, "Asia/Shanghai".
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimerWithDeviceId:(NSString *)devId
                     timezoneId:(NSString *)timezoneId
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;


/// Call this method to cancel the ongoing request.
- (void)cancelRequest;


#pragma mark - Timer

/// Set timers for each device or group.
/// @note The maximum number of timings per device or group is 30.
/// @param task The task name of the timer.
/// @param loops Number of loop.
/// @param bizId If it is a device, here is the device Id; if it is a group, here is the group id.
/// @param bizType Pass 0 if the type is device, otherwise, 1 for the group.
/// @param time Timed clocks under timed tasks.
/// @param dps Command Dictionary.
/// @param status A boolean value indicates whether to turn on the timer.
/// @param isAppPush A boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addTimerWithTask:(NSString *)task
                   loops:(NSString *)loops
                   bizId:(NSString *)bizId
                 bizType:(NSUInteger)bizType
                    time:(NSString *)time
                     dps:(NSDictionary *)dps
                  status:(BOOL)status
               isAppPush:(BOOL)isAppPush
               aliasName:(NSString *)aliasName
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure;


/// Get the timer under the specified task of the device or group.
/// @param task The name of the timer task.
/// @param bizId If it is a device, here is the device Id; if it is a group, here is the group id.
/// @param bizType Pass 0 if the type is device, otherwise, 1 for the group.
/// @param success Called when the task finishes successfully. A list of TYTimerTaskModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTimerListWithTask:(NSString *)task
                       bizId:(NSString *)bizId
                     bizType:(NSUInteger)bizType
                     success:(void(^)(NSArray<TYTimerModel *> *list))success
                     failure:(TYFailureError)failure;


/// Update the specified timer information for the specified task under the device or group.
/// @param timerId The timer ID for the update process.
/// @param loops Number of cycles, format "0000000". Each bit 0:off, 1:on, from left to right: Sunday Monday Tuesday Wednesday Thursday Friday Saturday. For example, each Monday: 0100000.
/// @param bizId If it is a device, here is the device Id; if it is a group, here is the group id.
/// @param bizType Pass 0 if the type is device, otherwise, 1 for the group.
/// @param time Timed time, e.g. 18:00.
/// @param dps Command Dictionary.
/// @param status A boolean value indicates whether to turn on the timer.
/// @param isAppPush A boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimerWithTimerId:(NSString *)timerId
                         loops:(NSString *)loops
                         bizId:(NSString *)bizId
                       bizType:(NSUInteger)bizType
                          time:(NSString *)time
                           dps:(NSDictionary *)dps
                        status:(BOOL)status
                     isAppPush:(BOOL)isAppPush
                     aliasName:(NSString *)aliasName
                       success:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;


/// Update the specified timer status for the specified task under the device or group.
/// @param timerId The timer ID for the update process.
/// @param bizId If it is a device, here is the device Id; if it is a group, here is the group id.
/// @param bizType Pass 0 if the type is device, otherwise, 1 for the group.
/// @param status A boolean value indicates whether to turn on the timer.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimerStatusWithTimerId:(NSString *)timerId
                               bizId:(NSString *)bizId
                             bizType:(NSUInteger)bizType
                              status:(BOOL)status
                             success:(TYSuccessHandler)success
                             failure:(TYFailureError)failure;


/// Update the status of all time clocks under a specific task.
/// @param task The name of the timer task.
/// @param bizId If it is a device, here is the device Id; if it is a group, here is the group id.
/// @param bizType Pass 0 if the type is device, otherwise, 1 for the group.
/// @param status A boolean value indicates whether to turn on the timer.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimerStatusWithTask:(NSString *)task
                            bizId:(NSString *)bizId
                          bizType:(NSUInteger)bizType
                           status:(BOOL)status
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;


/// Delete a single timer.
/// @param timerId The timer ID for the delete process.
/// @param bizId If it is a device, here is the device Id; if it is a group, here is the group id.
/// @param bizType Pass 0 if the type is device, otherwise, 1 for the group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeTimerWithTimerId:(NSString *)timerId
                         bizId:(NSString *)bizId
                       bizType:(NSUInteger)bizType
                       success:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;


/// Delete all timers under a specific task.
/// @param task The name of the timer task.
/// @param bizId If it is a device, here is the device Id; if it is a group, here is the group id.
/// @param bizType Pass 0 if the type is device, otherwise, 1 for the group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeTimerWithTask:(NSString *)task
                      bizId:(NSString *)bizId
                    bizType:(NSUInteger)bizType
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;


/// Batch modification of common timing status or deletion of timers.
/// @param timerIds Batch modified timing ids.
/// @param bizId Service id, in case of device, here is the device id; in case of group, here is the group id.
/// @param bizType Service type, 0:Device; 1:Device group.
/// @param updateType Update Type 0: Turn off the timer 1: Turn on the timer 2: Delete the timer.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimerStatusWithTimerIds:(NSArray<NSString *> *)timerIds
                                bizId:(NSString *)bizId
                              bizType:(NSUInteger)bizType
                           updateType:(int)updateType
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Modify all timing status under a timing task or delete a timer.
/// @param task Timing task name.
/// @param bizId Service id, in case of device, here is the device id; in case of group, here is the group id.
/// @param bizType Service type, 0:Device; 1:Device group.
/// @param updateType Update Type 0: Turn off the timer 1: Turn on the timer 2: Delete the timer.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimerTaskStatusWithTask:(NSString *)task
                                bizId:(NSString *)bizId
                              bizType:(NSUInteger)bizType
                           updateType:(NSUInteger)updateType
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;

@end

#endif
