#include <jack/jack.h>
typedef jack_client_t JackClient;
struct _jack_client { int x; };
const char *Jack_getDefaultAudioType() {
    return JACK_DEFAULT_AUDIO_TYPE;
}

typedef jack_port_t JackPort;
struct _jack_port { int x; };


#include "ext/Module.h"
#include "ext/Type.h"
#include "ext/Func.h"

extern "C"
void crack_ext__jack_rinit() {
    return;
}

extern "C"
void crack_ext__jack_cinit(crack::ext::Module *mod) {
    crack::ext::Func *f;
    crack::ext::Type *type_Class = mod->getClassType();
    crack::ext::Type *type_void = mod->getVoidType();
    crack::ext::Type *type_voidptr = mod->getVoidptrType();
    crack::ext::Type *type_bool = mod->getBoolType();
    crack::ext::Type *type_byteptr = mod->getByteptrType();
    crack::ext::Type *type_byte = mod->getByteType();
    crack::ext::Type *type_int16 = mod->getInt16Type();
    crack::ext::Type *type_int32 = mod->getInt32Type();
    crack::ext::Type *type_int64 = mod->getInt64Type();
    crack::ext::Type *type_uint16 = mod->getUint16Type();
    crack::ext::Type *type_uint32 = mod->getUint32Type();
    crack::ext::Type *type_uint64 = mod->getUint64Type();
    crack::ext::Type *type_int = mod->getIntType();
    crack::ext::Type *type_uint = mod->getUintType();
    crack::ext::Type *type_intz = mod->getIntzType();
    crack::ext::Type *type_uintz = mod->getUintzType();
    crack::ext::Type *type_float32 = mod->getFloat32Type();
    crack::ext::Type *type_float64 = mod->getFloat64Type();
    crack::ext::Type *type_float = mod->getFloatType();

    crack::ext::Type *array = mod->getType("array");

    crack::ext::Type *array_pfloat_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_float;
        array_pfloat_q = array->getSpecialization(params);
    }

    crack::ext::Type *type_JackPort = mod->addType("JackPort", sizeof(JackPort));

    f = type_JackPort->addMethod(
        array_pfloat_q,
        "getBuffer",
        (void *)jack_port_get_buffer
    );
    f->addArg(type_uint32,
              "frames"
              );


    f = type_JackPort->addMethod(
        type_byteptr,
        "getName",
        (void *)jack_port_name
    );

    type_JackPort->finish();


    crack::ext::Type *type_JackPosition = mod->addType("JackPosition", sizeof(jack_position_t));
        type_JackPosition->addInstVar(type_uint64, "usecs",
                                CRACK_OFFSET(jack_position_t, usecs));
        type_JackPosition->addInstVar(type_uint32, "frame_rate",
                                CRACK_OFFSET(jack_position_t, frame_rate));
        type_JackPosition->addInstVar(type_uint32, "frame",
                                CRACK_OFFSET(jack_position_t, frame));
        type_JackPosition->addInstVar(type_int, "valid",
                                CRACK_OFFSET(jack_position_t, valid));
        type_JackPosition->addInstVar(type_int32, "bar",
                                CRACK_OFFSET(jack_position_t, bar));
        type_JackPosition->addInstVar(type_int32, "beat",
                                CRACK_OFFSET(jack_position_t, beat));
        type_JackPosition->addInstVar(type_int32, "tick",
                                CRACK_OFFSET(jack_position_t, tick));
        type_JackPosition->addInstVar(type_float64, "bar_start_tick",
                                CRACK_OFFSET(jack_position_t, bar_start_tick));
        type_JackPosition->addInstVar(type_float32, "beats_per_bar",
                                CRACK_OFFSET(jack_position_t, beats_per_bar));
        type_JackPosition->addInstVar(type_float32, "beat_type",
                                CRACK_OFFSET(jack_position_t, beat_type));
        type_JackPosition->addInstVar(type_float64, "ticks_per_beat",
                                CRACK_OFFSET(jack_position_t, ticks_per_beat));
        type_JackPosition->addInstVar(type_float64, "beats_per_minute",
                                CRACK_OFFSET(jack_position_t, beats_per_minute));
    type_JackPosition->finish();


    crack::ext::Type *function = mod->getType("function");

    crack::ext::Type *function_pint_c_suint32_c_svoidptr_q;
    {
        std::vector<crack::ext::Type *> params(3);
        params[0] = type_int;
        params[1] = type_uint32;
        params[2] = type_voidptr;
        function_pint_c_suint32_c_svoidptr_q = function->getSpecialization(params);
    }

    crack::ext::Type *array_pbyteptr_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_byteptr;
        array_pbyteptr_q = array->getSpecialization(params);
    }

    crack::ext::Type *type_JackClient = mod->addType("JackClient", sizeof(JackClient));

    f = type_JackClient->addMethod(
        type_int,
        "setProcessCallback",
        (void *)jack_set_process_callback
    );
    f->addArg(function_pint_c_suint32_c_svoidptr_q,
              "callback"
              );
    f->addArg(type_voidptr,
              "arg"
              );


    f = type_JackClient->addMethod(
        type_JackPort,
        "portRegister",
        (void *)jack_port_register
    );
    f->addArg(type_byteptr,
              "port_name"
              );
    f->addArg(type_byteptr,
              "port_type"
              );
    f->addArg(type_uint,
              "flags"
              );
    f->addArg(type_uint,
              "buffer_size"
              );


    f = type_JackClient->addMethod(
        type_JackPort,
        "portByName",
        (void *)jack_port_by_name
    );
    f->addArg(type_byteptr,
              "name"
              );


    f = type_JackClient->addMethod(
        type_uint32,
        "getSampleRate",
        (void *)jack_get_sample_rate
    );


    f = type_JackClient->addMethod(
        type_int,
        "connect",
        (void *)jack_connect
    );
    f->addArg(type_byteptr,
              "port1"
              );
    f->addArg(type_byteptr,
              "port2"
              );


    f = type_JackClient->addMethod(
        type_int,
        "activate",
        (void *)jack_activate
    );


    f = type_JackClient->addMethod(
        type_int,
        "deactivate",
        (void *)jack_deactivate
    );


    f = type_JackClient->addMethod(
        array_pbyteptr_q,
        "getPorts",
        (void *)jack_get_ports
    );
    f->addArg(type_byteptr,
              "port_name_pattern"
              );
    f->addArg(type_byteptr,
              "type_name_pattern"
              );
    f->addArg(type_uint64,
              "flags"
              );


    f = type_JackClient->addMethod(
        type_uint32,
        "frameTime",
        (void *)jack_frame_time
    );


    f = type_JackClient->addMethod(
        type_uint32,
        "lastFrameTime",
        (void *)jack_last_frame_time
    );


    f = type_JackClient->addMethod(
        type_int,
        "transportLocate",
        (void *)jack_transport_locate
    );
    f->addArg(type_uint32,
              "pos"
              );


    f = type_JackClient->addMethod(
        type_int,
        "transportStart",
        (void *)jack_transport_start
    );


    f = type_JackClient->addMethod(
        type_int,
        "transportStop",
        (void *)jack_transport_stop
    );


    f = type_JackClient->addMethod(
        type_int,
        "transportQuery",
        (void *)jack_transport_query
    );
    f->addArg(type_JackPosition,
              "pos"
              );


    f = type_JackClient->addMethod(
        type_int,
        "transportReposition",
        (void *)jack_transport_reposition
    );
    f->addArg(type_JackPosition,
              "pos"
              );

    type_JackClient->finish();


    crack::ext::Type *array_pint_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_int;
        array_pint_q = array->getSpecialization(params);
    }
    f = mod->addFunc(type_byteptr, "Jack_getDefaultAudioType",
                     (void *)Jack_getDefaultAudioType
                     );

    f = mod->addFunc(type_JackClient, "JackClient_open",
                     (void *)jack_client_open
                     );
       f->addArg(type_byteptr, "name");
       f->addArg(type_int, "options");
       f->addArg(array_pint_q, "status");

    f = mod->addFunc(type_void, "Jack_free",
                     (void *)jack_free
                     );
       f->addArg(type_voidptr, "ptr");


    mod->addConstant(type_int, "JACK_NULL_OPTION",
                     static_cast<int>(JackNullOption)
                     );

    mod->addConstant(type_int, "JACK_NO_START_SERVER",
                     static_cast<int>(JackNoStartServer)
                     );

    mod->addConstant(type_int, "JACK_USE_EXACT_NAME",
                     static_cast<int>(JackUseExactName)
                     );

    mod->addConstant(type_int, "JACK_SERVER_NAME",
                     static_cast<int>(JackServerName)
                     );

    mod->addConstant(type_int, "JACK_LOAD_NAME",
                     static_cast<int>(JackLoadName)
                     );

    mod->addConstant(type_int, "JACK_LOAD_INIT",
                     static_cast<int>(JackLoadInit)
                     );

    mod->addConstant(type_int, "JACK_SESSION_ID",
                     static_cast<int>(JackSessionID)
                     );

    mod->addConstant(type_int, "JACK_PORT_IS_INPUT",
                     static_cast<int>(JackPortIsInput)
                     );

    mod->addConstant(type_int, "JACK_PORT_IS_OUTPUT",
                     static_cast<int>(JackPortIsOutput)
                     );

    mod->addConstant(type_int, "JACK_PORT_IS_PHYSICAL",
                     static_cast<int>(JackPortIsPhysical)
                     );

    mod->addConstant(type_int, "JACK_PORT_CAN_MONITOR",
                     static_cast<int>(JackPortCanMonitor)
                     );

    mod->addConstant(type_int, "JACK_PORT_IS_TERMINAL",
                     static_cast<int>(JackPortIsTerminal)
                     );

    mod->addConstant(type_int, "JACK_POSITION_BBT",
                     static_cast<int>(JackPositionBBT)
                     );

    mod->addConstant(type_int, "JACK_POSITION_TIMECODE",
                     static_cast<int>(JackPositionTimecode)
                     );

    mod->addConstant(type_int, "JACK_BBT_FRAME_OFFSET",
                     static_cast<int>(JackBBTFrameOffset)
                     );

    mod->addConstant(type_int, "JACK_TRANSPORT_STOPPED",
                     static_cast<int>(JackTransportStopped)
                     );

    mod->addConstant(type_int, "JACK_TRANSPORT_ROLLING",
                     static_cast<int>(JackTransportRolling)
                     );

    mod->addConstant(type_int, "JACK_TRANSPORT_LOOPING",
                     static_cast<int>(JackTransportLooping)
                     );

    mod->addConstant(type_int, "JACK_TRANSPORT_STARTING",
                     static_cast<int>(JackTransportStarting)
                     );
}
