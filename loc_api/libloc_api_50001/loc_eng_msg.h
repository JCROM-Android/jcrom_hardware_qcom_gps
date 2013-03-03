/* Copyright (c) 2011, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of Code Aurora Forum, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef LOC_ENG_MSG_H
#define LOC_ENG_MSG_H


#include <hardware/gps.h>
#include <stdlib.h>
#include <string.h>
#include "log_util.h"
#include "loc.h"
#include "loc_eng_log.h"
#include "loc_eng_msg_id.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct loc_eng_msg {
    const void* owner;
    const int msgid;
    inline loc_eng_msg(void* instance, int id) :
        owner(instance), msgid(id)
    {
        
    }
    virtual ~loc_eng_msg()
    {
        
    }
};

struct loc_eng_msg_suple_version : public loc_eng_msg {
    const int supl_version;
    inline loc_eng_msg_suple_version(void* instance, int version) :
        loc_eng_msg(instance, LOC_ENG_MSG_SUPL_VERSION),
        supl_version(version)
        {
            
        }
};

struct loc_eng_msg_sensor_control_config : public loc_eng_msg {
    const int sensorsDisabled;
    inline loc_eng_msg_sensor_control_config(void* instance, int disabled) :
            loc_eng_msg(instance, LOC_ENG_MSG_SET_SENSOR_CONTROL_CONFIG),
            sensorsDisabled(disabled)
        {
            
        }
};

struct loc_eng_msg_sensor_properties : public loc_eng_msg {
    const float gyroBiasVarianceRandomWalk;
    inline loc_eng_msg_sensor_properties(void* instance, float gyroBiasRandomWalk) :
            loc_eng_msg(instance, LOC_ENG_MSG_SET_SENSOR_PROPERTIES),
            gyroBiasVarianceRandomWalk(gyroBiasRandomWalk)
        {
            
        }
};

struct loc_eng_msg_sensor_perf_control_config : public loc_eng_msg {
    const int controlMode;
    const int accelSamplesPerBatch;
    const int accelBatchesPerSec;
    const int gyroSamplesPerBatch;
    const int gyroBatchesPerSec;
    inline loc_eng_msg_sensor_perf_control_config(void* instance, int controlMode,
                                                  int accelSamplesPerBatch, int accelBatchesPerSec,
                                                  int gyroSamplesPerBatch, int gyroBatchesPerSec) :
            loc_eng_msg(instance, LOC_ENG_MSG_SET_SENSOR_PERF_CONTROL_CONFIG),
            controlMode(controlMode),
            accelSamplesPerBatch(accelSamplesPerBatch),
            accelBatchesPerSec(accelBatchesPerSec),
            gyroSamplesPerBatch(gyroSamplesPerBatch),
            gyroBatchesPerSec(gyroBatchesPerSec)
        {
            
        }
};


struct loc_eng_msg_position_mode : public loc_eng_msg {
    const LocPositionMode pMode;
    const GpsPositionRecurrence pRecurrence;
    const uint32_t minInterval;
    const uint32_t preferredAccuracy;
    const uint32_t preferredTime;
    inline loc_eng_msg_position_mode() :
        loc_eng_msg(NULL, LOC_ENG_MSG_SET_POSITION_MODE),
        pMode(LOC_POSITION_MODE_STANDALONE),
        pRecurrence(0), minInterval(0),
        preferredAccuracy(0), preferredTime(0) {}
    inline loc_eng_msg_position_mode(void* instance,
                                     LocPositionMode mode,
                                     GpsPositionRecurrence recurrence,
                                     uint32_t min_interval,
                                     uint32_t preferred_accuracy,
                                     uint32_t preferred_time) :
        loc_eng_msg(instance, LOC_ENG_MSG_SET_POSITION_MODE),
        pMode(mode), pRecurrence(recurrence), minInterval(min_interval),
        preferredAccuracy(preferred_accuracy), preferredTime(preferred_time)
    {
        
    }
};

struct loc_eng_msg_set_time : public loc_eng_msg {
    const GpsUtcTime time;
    const int64_t timeReference;
    const int uncertainty;
    inline loc_eng_msg_set_time(void* instance,
                                GpsUtcTime t,
                                int64_t tf,
                                int unc) :
        loc_eng_msg(instance, LOC_ENG_MSG_SET_TIME),
        time(t), timeReference(tf), uncertainty(unc)
    {
        
    }
};

struct loc_eng_msg_inject_location : public loc_eng_msg {
    const double latitude;
    const double longitude;
    const float accuracy;
    inline loc_eng_msg_inject_location(void* instance, double lat,
                                       double longi, float accur) :
        loc_eng_msg(instance, LOC_ENG_MSG_INJECT_LOCATION),
        latitude(lat), longitude(longi), accuracy(accur)
    {
        
    }
};

struct loc_eng_msg_delete_aiding_data : public loc_eng_msg {
    const GpsAidingData type;
    inline loc_eng_msg_delete_aiding_data(void* instance, GpsAidingData data) :
        loc_eng_msg(instance, LOC_ENG_MSG_DELETE_AIDING_DATA), type(data)
    {
        
    }
};

struct loc_eng_msg_report_position : public loc_eng_msg {
    const GpsLocation location;
    const void* locationExt;
    const enum loc_sess_status status;
    inline loc_eng_msg_report_position(void* instance, GpsLocation &loc, void* locExt,
                                       enum loc_sess_status st) :
        loc_eng_msg(instance, LOC_ENG_MSG_REPORT_POSITION),
        location(loc), locationExt(locExt), status(st)
    {
#ifdef QCOM_FEATURE_ULP
        
#else
        
#endif
    }
};

struct loc_eng_msg_report_sv : public loc_eng_msg {
    const GpsSvStatus svStatus;
    const void* svExt;
    inline loc_eng_msg_report_sv(void* instance, GpsSvStatus &sv, void* ext) :
        loc_eng_msg(instance, LOC_ENG_MSG_REPORT_SV), svStatus(sv), svExt(ext)
    {
        
        for (int i = 0; i < svStatus.num_svs && i < GPS_MAX_SVS; i++) {
            
        }
    }
};

struct loc_eng_msg_report_status : public loc_eng_msg {
    const GpsStatusValue status;
    inline loc_eng_msg_report_status(void* instance, GpsStatusValue engineStatus) :
        loc_eng_msg(instance, LOC_ENG_MSG_REPORT_STATUS), status(engineStatus)
    {
        
    }
};

struct loc_eng_msg_report_nmea : public loc_eng_msg {
    char* const nmea;
    const int length;
    inline loc_eng_msg_report_nmea(void* instance,
                                   const char* data,
                                   int len) :
        loc_eng_msg(instance, LOC_ENG_MSG_REPORT_NMEA),
        nmea(new char[len]), length(len)
    {
        memcpy((void*)nmea, (void*)data, len);
        
    }
    inline ~loc_eng_msg_report_nmea()
    {
        delete[] nmea;
    }
};

struct loc_eng_msg_request_bit : public loc_eng_msg {
    const unsigned int isSupl;
    const int ipv4Addr;
    char* const ipv6Addr;
    inline loc_eng_msg_request_bit(void* instance,
                                   unsigned int is_supl,
                                   int ipv4,
                                   char* ipv6) :
        loc_eng_msg(instance, LOC_ENG_MSG_REQUEST_BIT),
        isSupl(is_supl), ipv4Addr(ipv4),
        ipv6Addr(NULL == ipv6 ? NULL : new char[16])
    {
        if (NULL != ipv6Addr)
            memcpy(ipv6Addr, ipv6, 16);
        
    }

    inline ~loc_eng_msg_request_bit()
    {
        if (NULL != ipv6Addr) {
            delete[] ipv6Addr;
        }
    }
};

struct loc_eng_msg_release_bit : public loc_eng_msg {
    const unsigned int isSupl;
    const int ipv4Addr;
    char* const ipv6Addr;
    inline loc_eng_msg_release_bit(void* instance,
                                   unsigned int is_supl,
                                   int ipv4,
                                   char* ipv6) :
        loc_eng_msg(instance, LOC_ENG_MSG_RELEASE_BIT),
        isSupl(is_supl), ipv4Addr(ipv4),
        ipv6Addr(NULL == ipv6 ? NULL : new char[16])
    {
        if (NULL != ipv6Addr)
            memcpy(ipv6Addr, ipv6, 16);
        
    }

    inline ~loc_eng_msg_release_bit()
    {
        if (NULL != ipv6Addr) {
            delete[] ipv6Addr;
        }
    }
};

struct loc_eng_msg_request_atl : public loc_eng_msg {
    const int handle;
    const AGpsType type;
    inline loc_eng_msg_request_atl(void* instance, int hndl,
                                   AGpsType agps_type) :
        loc_eng_msg(instance, LOC_ENG_MSG_REQUEST_ATL),
        handle(hndl), type(agps_type)
    {
        
    }
};

struct loc_eng_msg_release_atl : public loc_eng_msg {
    const int handle;
    inline loc_eng_msg_release_atl(void* instance, int hndl) :
        loc_eng_msg(instance, LOC_ENG_MSG_RELEASE_ATL), handle(hndl)
    {
        
    }
};

struct loc_eng_msg_request_ni : public loc_eng_msg {
    const GpsNiNotification notify;
    const void *passThroughData;
    inline loc_eng_msg_request_ni(void* instance,
                                  GpsNiNotification &notif, const void* data) :
        loc_eng_msg(instance, LOC_ENG_MSG_REQUEST_NI),
        notify(notif), passThroughData(data)
    {
        
    }
};

struct loc_eng_msg_inform_ni_response : public loc_eng_msg {
    const GpsUserResponseType response;
    const void *passThroughData;
    inline loc_eng_msg_inform_ni_response(void* instance,
                                          GpsUserResponseType resp,
                                          const void* data) :
        loc_eng_msg(instance, LOC_ENG_MSG_INFORM_NI_RESPONSE),
        response(resp), passThroughData(data)
    {
        
    }
    inline ~loc_eng_msg_inform_ni_response()
    {
        // this is a bit weird since passThroughData is not
        // allocated by this class.  But there is no better way.
        // passThroughData actually won't be NULL here.
        // But better safer than sorry.
        if (NULL != passThroughData) {
            free((void*)passThroughData);
        }
    }
};

struct loc_eng_msg_set_apn : public loc_eng_msg {
    char* const apn;
    inline loc_eng_msg_set_apn(void* instance, const char* name, int len) :
        loc_eng_msg(instance, LOC_ENG_MSG_SET_APN),
        apn(new char[len+1])
    {
        memcpy((void*)apn, (void*)name, len);
        apn[len] = 0;
        
    }
    inline ~loc_eng_msg_set_apn()
    {
        delete[] apn;
    }
};



struct loc_eng_msg_set_server_ipv4 : public loc_eng_msg {
    const unsigned int nl_addr;
    const int port;
    const LocServerType serverType;
    inline loc_eng_msg_set_server_ipv4(void* instance,
                                       unsigned int ip,
                                       int p,
                                       LocServerType type) :
        loc_eng_msg(instance, LOC_ENG_MSG_SET_SERVER_IPV4),
        nl_addr(ip), port(p), serverType(type)
    {
        
    }
};


struct loc_eng_msg_set_server_url : public loc_eng_msg {
    const int len;
    char* const url;
    inline loc_eng_msg_set_server_url(void* instance,
                                      const char* urlString,
                                      int url_len) :
        loc_eng_msg(instance, LOC_ENG_MSG_SET_SERVER_URL),
        len(url_len), url(new char[len+1])
    {
        memcpy((void*)url, (void*)urlString, url_len);
        url[len] = 0;
        
    }
    inline ~loc_eng_msg_set_server_url()
    {
        delete[] url;
    }
};

struct loc_eng_msg_inject_xtra_data : public loc_eng_msg {
    char* const data;
    const int length;
    inline loc_eng_msg_inject_xtra_data(void* instance, char* d, int l) :
        loc_eng_msg(instance, LOC_ENG_MSG_INJECT_XTRA_DATA),
        data(new char[l]), length(l)
    {
        memcpy((void*)data, (void*)d, l);
        
    }
    inline ~loc_eng_msg_inject_xtra_data()
    {
        delete[] data;
    }
};

#ifdef QCOM_FEATURE_IPV6
struct loc_eng_msg_atl_open_success : public loc_eng_msg {
    const AGpsStatusValue agpsType;
    const int length;
    char* const apn;
    const AGpsBearerType bearerType;
    inline loc_eng_msg_atl_open_success(void* instance,
                                        AGpsStatusValue atype,
                                        const char* name,
                                        int len,
                                        AGpsBearerType btype) :
        loc_eng_msg(instance, LOC_ENG_MSG_ATL_OPEN_SUCCESS),
        agpsType(atype), length(len),
        apn(new char[len+1]), bearerType(btype)
    {
        memcpy((void*)apn, (void*)name, len);
        apn[len] = 0;
        
    }
    inline ~loc_eng_msg_atl_open_success()
    {
        delete[] apn;
    }
};
#else
struct loc_eng_msg_atl_open_success : public loc_eng_msg {
    const int length;
    char* const apn;
    inline loc_eng_msg_atl_open_success(void* instance,
                                        const char* name,
                                        int len) :
        loc_eng_msg(instance, LOC_ENG_MSG_ATL_OPEN_SUCCESS),
        length(len),
        apn(new char[len+1])
    {
        memcpy((void*)apn, (void*)name, len);
        apn[len] = 0;
        
    }
    inline ~loc_eng_msg_atl_open_success()
    {
        delete[] apn;
    }
};
#endif

#ifdef QCOM_FEATURE_IPV6
struct loc_eng_msg_atl_open_failed : public loc_eng_msg {
    const AGpsStatusValue agpsType;
    inline loc_eng_msg_atl_open_failed(void* instance,
                                       AGpsStatusValue atype) :
        loc_eng_msg(instance, LOC_ENG_MSG_ATL_OPEN_FAILED),
        agpsType(atype)
    {
        
    }
};
#else
struct loc_eng_msg_atl_open_failed : public loc_eng_msg {
    inline loc_eng_msg_atl_open_failed(void* instance) :
        loc_eng_msg(instance, LOC_ENG_MSG_ATL_OPEN_FAILED)
    {
        
    }
};
#endif

#ifdef QCOM_FEATURE_IPV6
struct loc_eng_msg_atl_closed : public loc_eng_msg {
    const AGpsStatusValue agpsType;
    inline loc_eng_msg_atl_closed(void* instance,
                                  AGpsStatusValue atype) :
        loc_eng_msg(instance, LOC_ENG_MSG_ATL_CLOSED),
        agpsType(atype)
    {
        
    }
};
#else
struct loc_eng_msg_atl_closed : public loc_eng_msg {
    inline loc_eng_msg_atl_closed(void* instance) :
        loc_eng_msg(instance, LOC_ENG_MSG_ATL_CLOSED)
    {
        
    }
};
#endif

struct loc_eng_msg_set_data_enable : public loc_eng_msg {
    const int enable;
    char* const apn;
    const int length;
    inline loc_eng_msg_set_data_enable(void* instance,
                                       const char* name,
                                       int len,
                                       int yes) :
        loc_eng_msg(instance, LOC_ENG_MSG_ENABLE_DATA),
        enable(yes), apn(new char[len+1]), length(len)
    {
        memcpy((void*)apn, (void*)name, len);
        apn[len] = 0;
        
    }
    inline ~loc_eng_msg_set_data_enable()
    {
        delete[] apn;
    }
};

void loc_eng_msg_sender(void* loc_eng_data_p, void* msg);
int loc_eng_msgget(int * p_req_msgq);
int loc_eng_msgremove(int req_msgq);
int loc_eng_msgsnd(int msgqid, void * msgp);
int loc_eng_msgrcv(int msgqid, void ** msgp);
int loc_eng_msgsnd_raw(int msgqid, void * msgp, unsigned int msgsz);
int loc_eng_msgrcv_raw(int msgqid, void *msgp, unsigned int msgsz);
int loc_eng_msgflush(int msgqid);
int loc_eng_msgunblock(int msgqid);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LOC_ENG_MSG_H */
