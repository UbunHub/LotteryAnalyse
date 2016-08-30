//
//  HttpInterFace.h
//  SmartHome-iOS
//
//  Created by xiaoqy on 16/3/10.
//  Copyright © 2016年 xiaoqy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HttpRequest_OS.h"

@protocol HttpInterFaceDelegate <NSObject>

-(void)httpInterFaceDataCode:(NSInteger)dataCode
                     DataDic:(NSDictionary*)dataDic
               interFaceMode:(NSString*)interFaceMode;

@end

@interface HttpInterFace : NSObject

//请求数据类型
@property(assign, nonatomic) HTTPREQUEST_DATATYPE_INPUT inputDataType;

@property(weak, nonatomic) id<HttpInterFaceDelegate>delegate;

-(instancetype)initWithDelegate:(id<HttpInterFaceDelegate>)delegate;

/**
 * 登录
 * [in]userName 用户名
 * [in]passWord 密码
 */
-(void)logWithUserName:(NSString *)userName passWord:(NSString*)passWord;

/**
 * 注册
 * [in]tel 电话号码
 * [in]passWord 密码
 */
-(void)registerWithTelNO:(NSString*)tel passWord:(NSString*)passWord;

/**
 * 获取用户的场景列表
 * [in]userId 用户id
 * [in]userName 用户名
 */
-(void)getUserScenarioList:(NSString *)userId userName:(NSString*)userName;

/**
 * 获取彩票数据
 */
-(void)getFC3dDataWithPageSize:(NSString*)pageSize PageNum:(NSString*)pageNum;

/**
 *获取推荐的号码
 */
-(void)getRecommendCodeWithBeginOutNO:(NSString*)beginOutNO
                             EndOutNO:(NSString*)endOutNO
                          Probability:(NSString*)probability
                       RecommendOutON:(NSString*)recommendOutON;

- (void)getOmitDataWithPageSize:(NSString *)pageSize
                        pageNum:(NSString *)pageNum;
@end
