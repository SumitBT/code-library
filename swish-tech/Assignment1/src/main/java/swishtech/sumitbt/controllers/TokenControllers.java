package swishtech.sumitbt.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;
import swishtech.sumitbt.models.EmailConfirmationToken;
import swishtech.sumitbt.models.PasswordResetToken;
import swishtech.sumitbt.models.User;
import swishtech.sumitbt.repositories.EmailConfirmationTokenRepo;
import swishtech.sumitbt.repositories.PasswordResetTokenRepo;
import swishtech.sumitbt.repositories.UserRepo;

@RestController
public class TokenControllers
{
	@Autowired
	private UserRepo userRepo;
	
	@Autowired
	private EmailConfirmationTokenRepo emailConfirmationRepo;
	
	@Autowired
	private PasswordResetTokenRepo passwordResetTokenRepo;
	
	@RequestMapping(method=RequestMethod.GET, value="/confirm/{token}")
	public String getAll(@PathVariable String token)
	{
		EmailConfirmationToken ect = emailConfirmationRepo.findByToken(token);
		if(ect==null)
		{
			return "Wrong URL!";
		}
		else
		{
			User user = userRepo.findOne(ect.getUserId());
			user.setEnabled(true);
			userRepo.save(user);
			emailConfirmationRepo.delete(ect);
			return "Success";
		}
		
	}
	
	@RequestMapping(method=RequestMethod.POST, value="/reset/{token}")
	public String getAll(@PathVariable String token,@RequestBody User user)
	{
		String password = user.getPassword();
		if(password.equals(null))
		{
			return "password field can not be null";
		}
		PasswordResetToken prt = passwordResetTokenRepo.findByToken(token);
		if(prt==null)
		{
			return "Wrong URL!";
		}
		else
		{
			User user2 = userRepo.findOne(prt.getUserId());
			user2.setPassword(password);
			userRepo.save(user2);
			passwordResetTokenRepo.delete(prt);
			return "Success";
		}
	}
	
}
