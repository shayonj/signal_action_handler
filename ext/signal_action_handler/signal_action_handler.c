#include "ruby.h"
#include <stdio.h>
#include <signal.h>

static const struct signals {
  const char *signame;
  int signum;
} siginfo [] = {
  {"EXIT", 0},
#ifdef SIGHUP
  {"HUP", SIGHUP},
#endif
  {"INT", SIGINT},
#ifdef SIGQUIT
  {"QUIT", SIGQUIT},
#endif
#ifdef SIGTRAP
  {"TRAP", SIGTRAP},
#endif
#ifdef SIGABRT
  {"ABRT", SIGABRT},
#endif
#ifdef SIGIOT
  {"IOT", SIGIOT},
#endif
#ifdef SIGEMT
  {"EMT", SIGEMT},
#endif
#ifdef SIGKILL
  {"KILL", SIGKILL},
#endif
#ifdef SIGSYS
  {"SYS", SIGSYS},
#endif
#ifdef SIGPIPE
  {"PIPE", SIGPIPE},
#endif
#ifdef SIGALRM
  {"ALRM", SIGALRM},
#endif
#ifdef SIGTERM
  {"TERM", SIGTERM},
#endif
#ifdef SIGURG
  {"URG", SIGURG},
#endif
#ifdef SIGSTOP
  {"STOP", SIGSTOP},
#endif
#ifdef SIGTSTP
  {"TSTP", SIGTSTP},
#endif
#ifdef SIGCONT
  {"CONT", SIGCONT},
#endif
#ifdef SIGCHLD
  {"CHLD", SIGCHLD},
#endif
#ifdef SIGCLD
  {"CLD", SIGCLD},
#else
# ifdef SIGCHLD
  {"CLD", SIGCHLD},
# endif
#endif
#ifdef SIGTTIN
  {"TTIN", SIGTTIN},
#endif
#ifdef SIGTTOU
  {"TTOU", SIGTTOU},
#endif
#ifdef SIGIO
  {"IO", SIGIO},
#endif
#ifdef SIGXCPU
  {"XCPU", SIGXCPU},
#endif
#ifdef SIGXFSZ
  {"XFSZ", SIGXFSZ},
#endif
#ifdef SIGPROF
  {"PROF", SIGPROF},
#endif
#ifdef SIGWINCH
  {"WINCH", SIGWINCH},
#endif
#ifdef SIGUSR1
  {"USR1", SIGUSR1},
#endif
#ifdef SIGUSR2
  {"USR2", SIGUSR2},
#endif
#ifdef SIGLOST
  {"LOST", SIGLOST},
#endif
#ifdef SIGMSG
  {"MSG", SIGMSG},
#endif
#ifdef SIGPWR
  {"PWR", SIGPWR},
#endif
#ifdef SIGPOLL
  {"POLL", SIGPOLL},
#endif
#ifdef SIGDANGER
  {"DANGER", SIGDANGER},
#endif
#ifdef SIGMIGRATE
  {"MIGRATE", SIGMIGRATE},
#endif
#ifdef SIGPRE
  {"PRE", SIGPRE},
#endif
#ifdef SIGGRANT
  {"GRANT", SIGGRANT},
#endif
#ifdef SIGRETRACT
  {"RETRACT", SIGRETRACT},
#endif
#ifdef SIGSOUND
  {"SOUND", SIGSOUND},
#endif
#ifdef SIGINFO
  {"INFO", SIGINFO},
#endif
  {NULL, 0}
};
const struct signals *sigs;

// Define space for module
VALUE SignalActionHandler = Qnil;

// init module, used by ruby not here
void Init_signal_action_handler();

// prototype method name "info"
VALUE method_info(VALUE self);

void Init_signal_action_handler()
{
  SignalActionHandler = rb_define_class("SignalActionHandler", rb_cObject);
  rb_define_singleton_method(SignalActionHandler, "info", method_info, 0);
}

// method name "info"
VALUE method_info(VALUE self)
{
  VALUE h = rb_hash_new();
  struct sigaction oldact;
  const char *handler;

  for (sigs = siginfo; sigs->signame; sigs++)
  {
    sigaction(sigs->signum, NULL, &oldact);
    if (oldact.sa_handler == SIG_DFL)
    {
      handler = "SYSTEM_DEFAULT";
    }
    else if (oldact.sa_handler == SIG_IGN)
    {
      handler = "IGNORE";
    }
    else if (oldact.sa_handler == SIG_ERR)
    {
      handler = "ERROR";
    }
    else
    {
      handler = "DEFAULT";
    }
    rb_hash_aset(h, rb_str_new2(sigs->signame), rb_str_new2(handler));
  }

  return h;
}
