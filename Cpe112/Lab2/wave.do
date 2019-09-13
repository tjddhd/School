onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /lab2/inputa
add wave -noupdate /lab2/inputb
add wave -noupdate /lab2/outand
add wave -noupdate /lab2/outnand
add wave -noupdate /lab2/outor
add wave -noupdate /lab2/outnor
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {974 ps} 0}
configure wave -namecolwidth 109
configure wave -valuecolwidth 40
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {14117 ps}
