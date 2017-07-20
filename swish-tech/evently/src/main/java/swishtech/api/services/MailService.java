package swishtech.api.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.mail.MailException;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;
import swishtech.api.models.User;
import swishtech.api.repositories.EmailVerificationTokenRepo;
import swishtech.api.repositories.PasswordResetTokenRepo;

@Service
public class MailService
{
	private JavaMailSender jms;
	
	@Autowired
	public MailService(JavaMailSender jms)
	{
		this.jms = jms;
	}
	
	@Autowired
	private EmailVerificationTokenRepo emailVerificationTokenRepo;
	
	@Autowired
	private PasswordResetTokenRepo passwordResetTokenRepo;
	
	public void sendEmailVerificationMail(User user) throws MailException
	{
		SimpleMailMessage mail = new SimpleMailMessage();
		mail.setTo(user.getEmail());
		mail.setFrom("sumittamgale@gmail.com");
		mail.setSubject("Email Verification");
		mail.setText("Click the below link to confirm\n"+"http://192.168.43.233:8090/verify/"+emailVerificationTokenRepo.findByUserId(user.getUserId()).getToken());
		jms.send(mail);
	}
	
	public void sendPasswordResetMail(User user) throws MailException
	{
		SimpleMailMessage mail = new SimpleMailMessage();
		mail.setTo(user.getEmail());
		mail.setFrom("SumitBT");
		mail.setSubject("Password Reset");
		mail.setText("Click the below link to reset Password\n"+"http://localhost:8080/reset/?token="+passwordResetTokenRepo.findByUserId(user.getUserId()).getToken());
		jms.send(mail);
	}
}
