//
// TuyaSmartSIGMeshManager+Config.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>
NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartDeviceModel;

/// @brief SIG mesh activator Category for (SIG) bluetooth mesh manager.
///
/// Mainly contains device node control, reset and other functions. The core channels are also included and can send generic mesh messages.
@interface TuyaSmartSIGMeshManager (Config)

/// Reset node.
/// @param deviceModel TuyaSmartDeviceModel.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendNodeResetWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel
                             success:(nullable TYSuccessHandler)success
                             failure:(nullable TYFailureError)failure;

/// Switch command.
/// @param nodeId The node ID.
/// @param state Switch status.
/// @param useUnacknowledged Whether a reply is needed, it is suggested that the group should use no and single device control yes.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendOnoffWithNodeId:(NSString *)nodeId
                      state:(BOOL)state
          useUnacknowledged:(BOOL)useUnacknowledged
                    success:(nullable TYSuccessHandler)success
                    failure:(nullable TYFailureError)failure;

/// Brightness command.
/// @param nodeId The node ID.
/// @param brightValue Brightness value : 0 -- 65535.
/// @param useUnacknowledged Whether a reply is needed, it is suggested that the group should use no and single device control yes.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightBrightWithNodeId:(NSString *)nodeId
                      brightValue:(int)brightValue
                useUnacknowledged:(BOOL)useUnacknowledged
                          success:(nullable TYSuccessHandler)success
                          failure:(nullable TYFailureError)failure;

/// Heating and cooling control.
/// @param nodeId The node ID.
/// @param tempValue Warm and cold value : 300 - 20000.
/// @param useUnacknowledged Whether a reply is needed, it is suggested that the group should use no and single device control yes.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightCTLTempeValueWithNodeId:(NSString *)nodeId
                               tempValue:(int)tempValue
                       useUnacknowledged:(BOOL)useUnacknowledged
                                 success:(nullable TYSuccessHandler)success
                                 failure:(nullable TYFailureError)failure;

/// HLS color control.
/// @param nodeId The node ID.
/// @param aHue Hue value : 0 - 65535.
/// @param aSaturation Saturation : 0 - 65535.
/// @param aLightness brightness :  l or v，0 - 65535.
/// @param useUnacknowledged Whether a reply is needed, it is suggested that the group should use no and single device control yes.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightHSLWithNodeId:(NSString *)nodeId
                           hue:(int)aHue
                 andSaturation:(int)aSaturation
                     lightness:(int)aLightness
             useUnacknowledged:(BOOL)useUnacknowledged
                       success:(nullable TYSuccessHandler)success
                       failure:(nullable TYFailureError)failure;

/// Setup mode.
/// @param nodeId The node ID.
/// @param alightModel 0: white light mode. 1: Color light mode.
/// @param useUnacknowledged Whether a reply is needed, it is suggested that the group should use no and single device control yes.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightModelWithNodeId:(NSString *)nodeId
                      lightModel:(int)alightModel
               useUnacknowledged:(BOOL)useUnacknowledged
                         success:(nullable TYSuccessHandler)success
                         failure:(nullable TYFailureError)failure;

/// General vendor protocol.
/// @param nodeId The node ID.
/// @param vendorData Data content.
/// @param isisQuery Is it a query instruction.
/// @param useUnacknowledged Whether a reply is needed, it is suggested that the group should use no and single device control yes.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVendorDataWithNodeId:(NSString *)nodeId
                      vendorData:(NSData *)vendorData
                         isQuery:(BOOL)isisQuery
               useUnacknowledged:(BOOL)useUnacknowledged
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;

/// Custom channel, through the vendor instructions.
/// @param nodeId The node ID.
/// @param opCode opCode.
/// @param payload Metadata.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendCustomDataWithNodeId:(NSString *)nodeId
                          opCode:(int)opCode
                         payload:(NSData *)payload
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;

/// Single device sends messages.
/// @param nodeId The node ID.
/// @param schemaArray Dps information.
/// @param dps Dps.
/// @param pcc Product size class identification.
/// @param useUnacknowledged Do you need a message reply?
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpsWithNodeId:(NSString *)nodeId
                 schemaArray:(NSArray<TuyaSmartSchemaModel *> *)schemaArray
                         dps:(NSDictionary *)dps
                         pcc:(NSString *)pcc
           useUnacknowledged:(BOOL)useUnacknowledged
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

/// Gets the status of a device.
/// @param deviceModel The device model.
- (void)getDeviceStatusWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel;

/// Query device DPS.
/// @param deviceModel The device model.
/// @param dpIds DP ID group to query.
- (void)queryDpsWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel dpIds:(NSArray<NSString *> *)dpIds;

@end

NS_ASSUME_NONNULL_END
