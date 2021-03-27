//
// TuyaSmartMultiControl.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlLinkModel.h"
#import "TuyaSmartMultiControlModel.h"
#import "TuyaSmartMultiControlDpRelationModel.h"
#import "TuyaSmartMultiControlDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControl : NSObject

/// Query the multiple controls and automation associated with the dp button under the device.
/// @param devId Main device ID.
/// @param dpId DP ID.
/// @param success Called when the task finishes successfully. TuyaSmartMultiControlLinkModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceLinkInfoWithDevId:(NSString *)devId
                                dpId:(NSString *)dpId
                             success:(void (^)(TuyaSmartMultiControlLinkModel *))success
                             failure:(TYFailureError)failure;

/// Adding a multi-control group.
/// @param devId Main device ID.
/// @param groupName The group name.
/// @param groupDetail Multi-control group association details.
/// @param success Called when the task finishes successfully. TuyaSmartMultiControlModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addMultiControlWithDevId:(NSString *)devId
                       groupName:(NSString *)groupName
                     groupDetail:(NSArray<TuyaSmartMultiControlDetailModel *> *)groupDetail
                         success:(void (^)(TuyaSmartMultiControlModel *))success
                         failure:(TYFailureError)failure;

//// Update multi-Control group.
/// @param devId Main device ID.
/// @param model Multi-control group data model.
/// @param success Called when the task finishes successfully. TuyaSmartMultiControlModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)updateMultiControlWithDevId:(NSString *)devId
                  multiControlModel:(TuyaSmartMultiControlModel *)model
                            success:(void (^)(TuyaSmartMultiControlModel *))success
                            failure:(TYFailureError)failure;

/// Get dp point information of attached devices, associated multi-control, scene automation information.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. TuyaSmartMultiControlDpRelationModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceDpRelationWithDevId:(NSString *)devId
                               success:(void (^)(TuyaSmartMultiControlDpRelationModel *))success
                               failure:(TYFailureError)failure;


/// Enable or disable multiple control groups.
/// @param multiControlId Multi-control group ID.
/// @param enable A boolean value indicates whether to enable or disable the group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)enableMultiControlWithMultiControlId:(NSString *)multiControlId
                                      enable:(BOOL)enable
                                     success:(TYSuccessBOOL)success
                                     failure:(TYFailureError)failure;


/// Query the list of device IDs and the list of device groups (including user's and family's) that support performing actions.
/// @param homeId The home ID.
/// @param success Called when the task finishes successfully. A list of TuyaSmartMultiControlDeviceModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getMultiControlDeviceListWithHomeId:(long long)homeId
                                    success:(void (^)(NSArray<TuyaSmartMultiControlDeviceModel *> *))success
                                    failure:(TYFailureError)failure;


/// Get information about all dp points under the device.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. A list of TuyaSmartMultiControlDatapointModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceDpInfoWithDevId:(NSString *)devId
                         success:(void (^)(NSArray<TuyaSmartMultiControlDatapointModel *> *))success
                         failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
