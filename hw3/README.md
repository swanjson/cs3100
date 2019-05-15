I used htop, strace, the /proc filesystem and watch. I will post the commands I used below this paragraph. The context switches are increasing because I'm not exiting my program every time. SO they're compounded as I go down. Since I'm accessing my pi through SSH I didn't want to crash it because I wouldn't be able to reset it remotely; however, I note when I believe it will build to a crash.

htop:
$htop -d 1

strace:
$strace -p <PID>

/proc watch:
$pid=<PID>
$watch -e -d -n.1 cat /proc/$pid/status /proc/$pid/syscall /proc/$pid/wchan
OR
$watch -n.1 grep ctxt /proc/$pid/<which i want to look at>



addition operator

	htop: Originally all bars filled. Then CPU(green) went to 100% for one of the bars. Memory was at about 60%.
	/proc: context switches=266 voluntary, 709 nonvoluntary

	
function from cmath()

	htop: CPU(green) went to 100% for one of the bars. Sometimes all bars filled at 100% Memory was at about 60%.
	/proc: context switches=284 voluntary, 1818 nonvoluntary
	
new/delete

	htop: CPU(green) went to 100% for one of the bars, sometimes even exceeding 100. Memory was at about 60%.
	/proc: context switches=302 voluntary, 2893 nonvoluntary

	
just new operator

	htop: CPU(green) went to 100% for all of the bars. Memory filled up. 
	strace: Started infinitely adding memory addresses. Crashed by SIGKILL.
	/proc: context switches=14325 voluntary, 16527 nonvoluntary. Would have continued if I did not terminate the process.

	With strace I was able to visually see a memory leak. Very cool!
	

kill() wtih signal 0

	htop: Memory filled quickly and processing filled with green and bits of red.
	strace: Continually set the Kill Function. Lots of system calls.
	/proc: context switches=69538 voluntary, 511 nonvoluntary. Would have continued had I not terminated.

	It seemed like this is another memory leak. It wes taking a lot to make those calls.


kill() wtih signal SIGUSR2

	htop: Not run long enough to observe.
	strace: Says it was killed by SIGUSR2
	/proc: Couldn't run before the program quit.

	This is an interesting effect of SIGUSR2. Immediately shut down my program.

clock()

	htop: Memory filled quickly and process CPU % increaded and bounced around.
	strace: Filled the terminal with clock_gettime functions over and over.
	/proc: context switches=37528 voluntary, 510 nonvoluntary. Would have continued had I not terminated.
 
	I'm noticing a trend for process calls.

nanosleep() with a delay of 1ns

	htop: Memory filled quickly and process CPU % increaded and bounced around.
	strace: Filled the terminal with nanosleep functions over and over.
	/proc: context switches=84286 voluntary, 1789 nonvoluntary. Would have continued had I not terminated.

nanosleep() with a delay of 1,000ns

	htop: Memory filled quickly and process CPU % increaded and bounced around.
	strace: Filled the terminal with nanosleep functions over and over.
	/proc: context switches=143913 voluntary, 2286 nonvoluntary. Would have continued had I not terminated.

	Almost the same as 1ns. Maybe it is calling a bit slower?

nanosleep() with a delay of 1,000,000ns

	htop: Memory filled quickly and process CPU % increaded and bounced around.
	strace: Filled the terminal with nanosleep functions over and over.
	/proc: context switches=150330 voluntary, 2305 nonvoluntary. Would have continued had I not terminated.

	Almost the same as 1,000ns. Maybe it is calling a bit slower?


nanosleep() with a delay of 1,000,000,000ns

	htop: Memory filled quickly and process CPU % increaded and bounced around.
	strace: Filled the terminal with nanosleep functions over and over.
	/proc: context switches=214502 voluntary, 2407 nonvoluntary. Would have continued had I not terminated.

	Almost the same as 1,000,000ns. Maybe it is calling a bit slower?


fork()  with exit() and wait()

	htop: Memory filled quickly and process CPU % increaded and bounced around.
	strace: Filled the terminal with SIGCHLD calls over and over. Mostly making "clones".
	/proc: context switches=217805 voluntary, 3866 nonvoluntary. Would have continued had I not terminated.

	These calls were very rapid. Would lead to crash?

getcwd()

	htop: Memory filled quickly and process CPU % increaded and bounced around. Mostly Red.
	strace: Filled the terminal with getcwd  calls over and over to my current directory.
	/proc: context switches=358429 voluntary, 5247 nonvoluntary. Would have continued had I not terminated.

	These calls were very rapid. Would lead to crash?

chdir()

	htop: Memory filled quickly and process CPU % increaded and bounced around. Mostly Red.
	strace: Filled the terminal with chdir calls over and over to a directory that doesn't exist.
	/proc: context switches=368515 voluntary, 5616 nonvoluntary. Would have continued had I not terminated.

	These calls were very rapid. Would lead to crash?

access()

	htop: Memory filled quickly and process CPU % increaded and bounced around. Mostly Red.
	strace: Filled the terminal with access calls over and over to a location that doesn't exist.
	/proc: context switches=396885 voluntary, 5942 nonvoluntary. Would have continued had I not terminated.

	These calls were very rapid. Would lead to crash? Even if invalid?


sync()

	htop: Memory filled quickly and process CPU % increaded and bounced around. Mostly Red.
	strace: Filled the terminal with sync calls over and over to equal zero.
	/proc: context switches=424228 voluntary, 10941 nonvoluntary. Would have continued had I not terminated.

	These calls were very rapid. Would lead to crash?

chmod()

	htop: Memory filled quickly and process CPU % increaded and bounced around. Mostly Red.
	strace: Filled the terminal with chmod calls over and over setting "/proc/self/exe" to equal zero.
	/proc: context switches=435227 voluntary, 10973 nonvoluntary. Would have continued had I not terminated.

	These calls were very rapid. Would lead to crash?

dup2()

	htop: Memory filled quickly and process CPU % increaded and bounced around. Mostly Red.
	strace: Filled the terminal with dup2(1,2) calls over and over setting it to equal 2.
	/proc: context switches=536438 voluntary, 11001 nonvoluntary. Would have continued had I not terminated. This was a much faster increase.

	These calls were very rapid. Would lead to crash? This took much longer for the SIGINT (ctrl+C) to work.


